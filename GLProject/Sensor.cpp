#include "Sensor.h"
namespace data {

    Sensor::Sensor(const std::string &sensorId, double score, bool privateSensor, const std::string &description,
                   const std::list<AirQualityData> &myData) : sensorID(sensorId), score(score),
                                                              privateSensor(privateSensor), description(description),
                                                              myData(myData) {

    }
}