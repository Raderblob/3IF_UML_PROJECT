#include "AirQualityManager.h"
#include <fstream>
#include "Util.h"
#include "Sensor.h"
#include "AirQualityData.h"
#include <iostream>
using namespace std;

AirQualityManager::~AirQualityManager() {
    cout << "Deleting Data\n";
    for (int i = 0; i < (int)data.size(); ++i) {
        delete data.at(i);
    }
    
}

AirQualityManager::AirQualityManager() {

}

void AirQualityManager::saveEverything() const {

}

void AirQualityManager::loadEverything() {
    loadData();
}

void AirQualityManager::print()
{
    for (int i = 0; i < (int)data.size(); i++) {
        std::cout<< data.at(i)->toString() + "\n";
    }
}

void AirQualityManager::loadSensors() {

}

void AirQualityManager::loadCleaners() {

}

void AirQualityManager::loadData()
{
	ifstream dataFile;
	dataFile.open("dataset/measurements.csv");
    int idCounter = 0;
    if (dataFile.is_open()) {
        while (!dataFile.eof()) {
            string str;
            getline(dataFile, str, '\n');
            vector<string> vec= Util::splitString(str, ';');
            if (vec.size() == 5) {
                data.push_back(new data::AirQualityData(idCounter++, vec.at(2), vec.at(0)));
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
