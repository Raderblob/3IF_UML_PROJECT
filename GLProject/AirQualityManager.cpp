#include <fstream>
#include "AirQualityManager.h"
#include "Util.h"

using namespace std;

AirQualityManager::~AirQualityManager() {

}

AirQualityManager::AirQualityManager() {
    loadSensors();
    userManager.loadUsers();
    loadCleaners();
}

void AirQualityManager::saveEverything() const {
    saveCleaners();
    saveSensors();

    userManager.saveUsers();
}

void AirQualityManager::loadSensors() {

}

void AirQualityManager::loadCleaners() {

}

void AirQualityManager::saveCleaners() const {
    fstream file;
    file.open("dataset/cleaners.csv",ios::out);

    if(file.is_open()) {
        auto it = cleaners.begin();
        while (it != cleaners.end()) {
            string str = it->second->toString();
            file<<str<<";"<<endl;

            it = ++it;
        }
    }
    file.close();
}

void AirQualityManager::saveSensors() const {
    fstream file;
    file.open("dataset/sensors.csv",ios::out);

    if(file.is_open()) {
        auto it = sensors.begin();
        while (it != sensors.end()) {
            string str = it->second->toString();
            file<<str<<";"<<endl;

            it = ++it;
        }
    }
    file.close();
}

void AirQualityManager::saveData() const {
    fstream file;
    file.open("dataset/data.csv",ios::out);

    if(file.is_open()) {
        auto it = data.begin();
        while (it != data.end()) {
            string str;
            str = it->toString();
            file<<str<<";"<<endl;

            it = ++it;
        }
    }
    file.close();
}
