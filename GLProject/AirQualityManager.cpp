#include "AirQualityManager.h"
#include <fstream>
#include "Util.h"
#include "Sensor.h"
#include "AirQualityData.h"
#include <iostream>
#include <chrono>

using namespace std;

AirQualityManager::~AirQualityManager() {
#ifdef DEBUG
    std::cout << "Destructor for AirQualityManager" << std::endl;
#endif // DEBUG
    for (auto sensor : sensors) {
        delete sensor.second;
    }
    for (auto cleaner : cleaners) {
        delete cleaner.second;
    }
    delete sensorTree;
}

AirQualityManager::AirQualityManager() {
#ifdef DEBUG
    std::cout << "Constructor for AirQualityManager" << std::endl;
#endif // DEBUG
    sensorTree = nullptr;
}

void AirQualityManager::saveEverything() const {

}

void AirQualityManager::loadEverything() {
    loadSensors();
    loadData();
    loadCleaners();
}

double AirQualityManager::getMeanAirQuality(const data::Coordinate& centerPoint, const double& totalWidth) const
{
    vector<data::Sensor*> sensorsInArea = sensorTree->searchPoint(centerPoint, totalWidth);
    int totalIndex = 0, counter = 0;
    for (auto sensor : sensorsInArea) {
        for (auto internalData : sensor->getData()) {
            counter++;
            totalIndex += internalData->getAtmo();
        }
        
    }
    return ((double)totalIndex) / ((double)counter);

}

double AirQualityManager::getMeanAirQualityWithDate(const data::Coordinate& centerPoint, const double& totalWidth, const std::string& startTime, const std::string& endTime) const
{
    return getMeanAirQualityWithDate(centerPoint, totalWidth, Util::dateToLong(startTime), Util::dateToLong(endTime));
}

double AirQualityManager::getMeanAirQualityWithDate(const data::Coordinate& centerPoint, const double& totalWidth, const unsigned long& startTime, const unsigned long& endTime) const
{
    vector<data::Sensor*> sensorsInArea = sensorTree->searchPoint(centerPoint, totalWidth);
    int totalIndex = 0, counter = 0;
    for (auto sensor : sensorsInArea) {
        for (auto internalData : sensor->getData()) {
            if ((*internalData) < endTime && !((*internalData) < startTime)) {
                counter++;
                totalIndex += internalData->getAtmo();
            }
        }

    }
    return ((double)totalIndex) / ((double)counter);
}

const std::map<std::string, AirCleaner*>& AirQualityManager::getCleaners() const
{
    return cleaners;
}

double AirQualityManager::getAreaOfEffectOfCleaner(const AirCleaner& cl,const double& step ,const bool& ratio, double maxOrRatio) const
{
    double startingArea = 0.5;
    double avgIndex;
    double nIndex;
    if (!ratio) {
        nIndex = 0.1;
    }
    do {
        startingArea += step;
        nIndex = getMeanAirQualityWithDate(cl.getPosition(), startingArea, cl.getTime1(), cl.getTime2());
        if (ratio) {
            avgIndex = getMeanAirQuality(cl.getPosition(), startingArea);
        }
    } while (( ratio && ( nIndex<avgIndex/maxOrRatio)) ||( !ratio &&(nIndex<=maxOrRatio)));
    startingArea -= step;
    return (startingArea==0.5?0:startingArea);
}



void AirQualityManager::print()
{
#ifdef DEBUG

    for (auto sensor :sensors) {
        std::cout << "Sensor " << sensor.first << std::endl;
        for (auto d : sensor.second->getData()) {
             std::cout<<d->toString() + "\n";
        }
    }


    int counter = 0;
    for (double i = 40; i < 50; i += 0.5) {
        for (double j = -2; j < 10; j += 0.5) {
            counter += (int) sensorTree->searchPoint(data::Coordinate(i, j), 0.5).size();
        }
    }
    cout << counter << endl;

#endif // DEBUG
    cout << "Sensors:" << endl;
    for (auto s : sensors) {
        std::cout << s.second->toString() << std::endl;
    }
    cout << "Cleaners:" << endl;
    for (auto cleaner : cleaners) {
        std::cout << cleaner.second->toString() << std::endl;
    }
}

void AirQualityManager::loadSensors() {
    Util::startTimer();
    ifstream dataFile;
    dataFile.open("dataset/sensors.csv");
    int idCounter = 0;
    if (dataFile.is_open()) {
        while (!dataFile.eof()) {
            string str;
            getline(dataFile, str, '\n');
            vector<string> vec = Util::splitString(str, ';');
            if (vec.size() == 4) {
                sensors.insert({ vec.at(0),new data::Sensor(vec.at(0), 0, false, data::Coordinate(std::stod(vec.at(1)), std::stod(vec.at(2))),"") });
            }
        }
    }
    dataFile.close();


    for (auto sens : sensors) {
        data::Coordinate gridCoord = sens.second->getPosition().getGridCoords(2);
        auto el = regionSensorLists.find(gridCoord);
        if (el == regionSensorLists.end()) {
            vector<data::Sensor*> newList;
            newList.push_back(sens.second);
            regionSensorLists.insert({ gridCoord,newList});
        }
        else {
            el->second.push_back(sens.second);
        }
    }
    vector<data::Sensor*> bruteSensors;
    for (auto sens : sensors) {
        bruteSensors.push_back(sens.second);
    }
    sensorTree = new data::tree::QuadTree(bruteSensors);
    Util::stopTimer("LoadSensors");
}

void AirQualityManager::loadCleaners() {
    Util::startTimer();
    ifstream dataFile;
    dataFile.open("dataset/cleaners.csv");
    int idCounter = 0;
    if (dataFile.is_open()) {
        while (!dataFile.eof()) {
            string str;
            getline(dataFile, str, '\n');
            vector<string> vec = Util::splitString(str, ';');
            if (vec.size() == 7) {
                cleaners.insert({ vec.at(0),new AirCleaner(vec.at(0),data::Coordinate(std::stod(vec.at(1)),std::stod(vec.at(2))),Util::dateToLong(vec.at(4)),Util::dateToLong(vec.at(5))) });
            }
        }
    }
    dataFile.close();
    Util::stopTimer("LoadCleaners");
}

void AirQualityManager::loadData()
{
    Util::startTimer();
	ifstream dataFile;
	dataFile.open("dataset/measurements.csv");
    data::Sensor* sensor = nullptr;
    data::AirQualityData* cData = nullptr;
    if (dataFile.is_open()) {
        while (!dataFile.eof()) {
            string str;
            getline(dataFile, str, '\n');
            vector<string> vec = Util::splitString(str, ';');
            if (vec.size() == 5) {
                data::Reading* nReading = new data::Reading(vec.at(2), std::stod(vec.at(3)));


                if (sensor == nullptr || sensor->getId() != vec.at(1)) {
                    if (cData != nullptr) {
                        sensor->addData(cData);
                        cData = nullptr;
                    }
                    sensor = sensors.find(vec.at(1))->second;
                }



                unsigned long readTime = Util::dateToLong(vec.at(0));
                if (cData == nullptr|| readTime != cData->getTime() || cData->getSensorId() != vec.at(1)) {
                    if (cData != nullptr) {
                        sensor->addData(cData);
                    }
                    cData = new data::AirQualityData(readTime, sensor, nReading);
                }
                else {
                    cData->addReading(nReading);
                }

            }
        }
        sensor->addData(cData);
    }
    dataFile.close();
    Util::stopTimer("load Date");
}

void AirQualityManager::saveCleaners() const {

}

void AirQualityManager::saveSensors() const {

}

void AirQualityManager::saveData() const {

}
