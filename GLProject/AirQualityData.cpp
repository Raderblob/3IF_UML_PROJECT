#include "AirQualityData.h"
namespace data {
	AirQualityData::AirQualityData(const std::string& u, const std::string& descr, const data::Sensor* nSensor)
	{
		static int idCounter = 0;
		attributeId = idCounter++;
		unit = u;
		description = descr;
		mySensor = nSensor;

	}
	AirQualityData::~AirQualityData()
	{
	}

    std::string AirQualityData::toString() const {
	    std::string res = std::to_string(attributeId) + ";" + unit + ";" + description;

        return res;
    }
}