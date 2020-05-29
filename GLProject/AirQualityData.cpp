#include "AirQualityData.h"
#include "Util.h"
#include "Sensor.h"
namespace data {
	AirQualityData::AirQualityData(const unsigned long& mTime, const data::Sensor* nSensor, Reading* mReading)
	{
		static int idCounter = 0;
		attributeId = idCounter++;

		mySensor = nSensor;

		readings.push_back(mReading);

		time = mTime;
	}
	AirQualityData::~AirQualityData()
	{
		for (auto reading : readings) {
			delete reading;
		}
	}

    std::string AirQualityData::toString() const {
	    std::string res = std::to_string(attributeId)  + ";" + std::to_string(time) + ";" ;
		for (auto reading : readings) {
			res += "reading: "  + std::to_string(reading->getValue()) + ";";
		}


        return res;
    }
	const unsigned long& AirQualityData::getTime() const
	{
		return time;
	}
	void AirQualityData::addReading(Reading* nReading)
	{
		readings.push_back(nReading);
	}
	const std::string& AirQualityData::getSensorId() const
	{
		return mySensor->getId();
	}
}