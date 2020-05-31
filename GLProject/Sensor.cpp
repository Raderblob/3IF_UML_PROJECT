#include "Sensor.h"
namespace data {

  

    std::string Sensor::toString() const {
        return sensorID +";" + std::to_string(score) + ";" + (privateSensor? "1" : "0") + ";" + description;
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
        this->sensorID = sensorID;
        this->score = score;
        this->privateSensor = privateSensor;
        this->myPosition = aCoord;
        this->description = descr;
    }
    Sensor::~Sensor()
    {
        for (auto data : myData) {
            delete data;
        }
    }
}