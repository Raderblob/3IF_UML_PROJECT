#include "Sensor.h"
namespace data {

  

    std::string Sensor::toString() const {
        return sensorID +";" + std::to_string(score) + ";" + (privateSensor? "1" : "0") + ";" + description;
    }
}