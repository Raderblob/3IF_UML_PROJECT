#include "AirQualityManager.h"

AirQualityManager::~AirQualityManager() {

}

AirQualityManager::AirQualityManager() {

}

void AirQualityManager::saveEverything() const {
    userManager.saveUsers();
}
