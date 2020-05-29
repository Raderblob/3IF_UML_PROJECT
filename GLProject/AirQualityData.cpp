#include "AirQualityData.h"
#include "Util.h"
namespace data {
	AirQualityData::AirQualityData(const std::string& u, const std::string& descr, const data::Sensor* nSensor,const double& val)
	{
		static int idCounter = 0;
		attributeId = idCounter++;
		unit = u;
		mySensor = nSensor;
		value = val;


		time = Util::dateToLong(descr);
	}
	AirQualityData::~AirQualityData()
	{
	}

    std::string AirQualityData::toString() const {
	    std::string res = std::to_string(attributeId) + ";" + unit + ";" + std::to_string(time) + ";" + std::to_string(value) ;

        return res;
    }
}