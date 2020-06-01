#include "Sensor.h"
#include <iostream>
namespace data {

  

    std::string Sensor::toString() const {
        return sensorID + ";" + myPosition.toString() + ";";
    }
    void Sensor::addData(AirQualityData* nData)
    {
        myData.push_back(nData);
    }
    const std::vector<AirQualityData*>& Sensor::getData() const
    {
        return myData;
    }
    const std::string& Sensor::getId() const
    {
        return sensorID;
    }
    const Coordinate& Sensor::getPosition() const
    {
        return myPosition;
    }
    Sensor::Sensor(const std::string& sensorID, const int& score, const bool& privateSensor, const Coordinate& aCoord, const std::string descr)
    {
#ifdef DEBUG
        std::cout << "Constructor for Sensor" << std::endl;
#endif // DEBUG
        this->sensorID = sensorID;
        this->score = score;
        this->privateSensor = privateSensor;
        this->myPosition = aCoord;
        this->description = descr;
    }
    Sensor::~Sensor()
    {
#ifdef DEBUG
        std::cout << "Destructor for Sensor" << std::endl;
#endif // DEBUG
        for (auto data : myData) {
            delete data;
        }
    }
}