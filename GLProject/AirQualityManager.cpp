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


    userManager.saveUsers();
}

void AirQualityManager::loadSensors() const {
    fstream file;
    file.open("dataset/sensors.csv",ios::in);
    if(file.is_open()) {
        while(!file.eof()){
            string str;
            file>>str;
            vector<string> vec = Util::splitString(str,';');
            if(vec.size()==6) {
               // sensors.insert({vec.at(0), new users::User(vec.at(1), vec.at(2), vec.at(0), vec.at(3), vec.at(4))});
            }
        }
    }
    file.close();


}

void AirQualityManager::loadCleaners() const {

}
