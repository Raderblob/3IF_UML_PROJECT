#include "AirQualityManager.h"
#include <fstream>
#include "Util.h"
#include "Sensor.h"
#include "AirQualityData.h"
#include <iostream>
using namespace std;

AirQualityManager::~AirQualityManager() {
    cout << "Deleting Data\n";
    for (auto sensor : sensors) {
        delete sensor.second;
    }
    
}

AirQualityManager::AirQualityManager() {

}

void AirQualityManager::saveEverything() const {

}

void AirQualityManager::loadEverything() {
    loadSensors();
    loadData();
}

void AirQualityManager::print()
{
    for (auto sensor :sensors) {
        std::cout << "Sensor " << std::endl;
        for (auto d : sensor.second->getData()) {
             std::cout<<d->toString() + "\n";
        }
       
    }
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
                sensors.insert({ vec.at(0),new data::Sensor(vec.at(0), 0, false, data::Coordinate(std::stoi(vec.at(1)), std::stoi(vec.at(2))),"") });
            }
        }
    }
    dataFile.close();

    for (auto sens : sensors) {

    }
}

void AirQualityManager::loadCleaners() {

}

void AirQualityManager::loadData()
{
	ifstream dataFile;
	dataFile.open("dataset/measurements.csv");
    if (dataFile.is_open()) {
        while (!dataFile.eof()) {
            string str;
            getline(dataFile, str, '\n');
            vector<string> vec= Util::splitString(str, ';');
            if (vec.size() == 5) {
                data::Sensor* sensor = sensors.find(vec.at(1))->second;
                data::AirQualityData* nData = new data::AirQualityData(vec.at(2), vec.at(0), sensor);
                sensor->addData(nData);
            }
        }
    }
    dataFile.close();
}

void AirQualityManager::saveCleaners() const {

}

void AirQualityManager::saveSensors() const {

}

void AirQualityManager::saveData() const {

}
