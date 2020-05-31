#include "AirQualityManager.h"
#include <fstream>
#include "Util.h"
#include "Sensor.h"
#include "AirQualityData.h"
#include <iostream>
#include <chrono>

using namespace std;

AirQualityManager::~AirQualityManager() {
    cout << "Deleting Data\n";
    for (auto sensor : sensors) {
        delete sensor.second;
    }
    delete sensorTree;
}

AirQualityManager::AirQualityManager() {
    sensorTree = nullptr;
}

void AirQualityManager::saveEverything() const {

}

void AirQualityManager::loadEverything() {
    auto startTime = std::chrono::steady_clock::now();
    loadSensors();
    auto endTime = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << "[ms]" << std::endl;
    startTime = std::chrono::steady_clock::now();
    loadData();
    endTime = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << "[ms]" << std::endl;
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



void AirQualityManager::print()
{
    for (auto sensor :sensors) {
        std::cout << "Sensor " << sensor.first << std::endl;
        for (auto d : sensor.second->getData()) {
             std::cout<<d->toString() + "\n";
        }
    }

    for (auto gridSquare : regionSensorLists) {
        std::cout << gridSquare.first.toString() << std::endl;
        for (auto sensor : gridSquare.second) {
            std::cout << sensor->getId() << " " <<sensor->getPosition().toString() << std::endl;
        }
    }

    int counter = 0;
    for (double i = 40; i < 50; i += 0.5) {
        for (double j = -2; j < 10; j += 0.5) {
            counter += sensorTree->searchPoint(data::Coordinate(i, j), 0.5).size();
        }
    }
    cout << counter << endl;
}

void AirQualityManager::loadSensors() {
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

}

void AirQualityManager::loadCleaners() {

}

void AirQualityManager::loadData()
{
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
}

void AirQualityManager::saveCleaners() const {

}

void AirQualityManager::saveSensors() const {

}

void AirQualityManager::saveData() const {

}
