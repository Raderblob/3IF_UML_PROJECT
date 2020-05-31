#include "AirQualityData.h"
#include "Util.h"
#include "Sensor.h"
#include <stdexcept>
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
			res +=reading->getType()  + " " + std::to_string(reading->getValue()) + ";";
		}
		res += "ATMO: " + std::to_string(getAtmo());

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
	int AirQualityData::getAtmo() const
	{
		int atmO3=1, atmSO2=1, atmNO2=1, atmPM10=1;
		double O3 = getO3();
		double SO2 = getSO2();
		double NO2 = getNO2();
		double PM10 = getPM10();

		if (O3 >= 240) {
			atmO3 = 10;
		}
		else if (O3 >= 210) {
			atmO3 = 9;
		}
		else if (O3 >= 180) {
			atmO3 = 8;
		}
		else if (O3 >= 150) {
			atmO3 = 7;
		}
		else if (O3 >= 130) {
			atmO3 = 6;
		}
		else if (O3 >= 105) {
			atmO3 = 5;
		}
		else if (O3 >= 80) {
			atmO3 = 4;
		}
		else if (O3 >= 55) {
			atmO3 = 3;
		}
		else if (O3 >= 30) {
			atmO3 = 2;
		}
		
		if (SO2 >= 500) {
			atmSO2 = 10;
		}
		else if (SO2 >= 400) {
			atmSO2 = 9;
		}
		else if (SO2 >= 300) {
			atmSO2 = 8;
		}
		else if (SO2 >= 250) {
			atmSO2 = 7;
		}
		else if (SO2 >= 200) {
			atmSO2 = 6;
		}
		else if (SO2 >= 160) {
			atmSO2 = 5;
		}
		else if (SO2 >= 120) {
			atmSO2 = 4;
		}
		else if (SO2 >= 80) {
			atmSO2 = 3;
		}
		else if (SO2 >= 40) {
			atmSO2 = 2;
		}

		if (NO2 >= 400) {
			atmNO2 = 10;
		}
		else if (NO2 >= 275) {
			atmNO2 = 9;
		}
		else if (NO2 >= 200) {
			atmNO2 = 8;
		}
		else if (NO2 >= 165) {
			atmNO2 = 7;
		}
		else if (NO2 >= 135) {
			atmNO2 = 6;
		}
		else if (NO2 >= 110) {
			atmNO2 = 5;
		}
		else if (NO2 >= 85) {
			atmNO2 = 4;
		}
		else if (NO2 >= 55) {
			atmNO2 = 3;
		}
		else if (NO2 >= 30) {
			atmNO2 = 2;
		}

		if (PM10 >= 80) {
			atmPM10 = 10;
		}
		else if (PM10 >= 65) {
			atmPM10 = 9;
		}
		else if (PM10 >= 50) {
			atmPM10 = 8;
		}
		else if (PM10 >= 42) {
			atmPM10 = 7;
		}
		else if (PM10 >= 35) {
			atmPM10 = 6;
		}
		else if (PM10 >= 28) {
			atmPM10 = 5;
		}
		else if (PM10 >= 21) {
			atmPM10 = 4;
		}
		else if (PM10 >= 14) {
			atmPM10 = 3;
		}
		else if (PM10 >= 7) {
			atmPM10 = 2;
		}

		int res = (atmO3 > atmSO2 ? atmO3 : atmSO2);
		res = (res > atmNO2 ? res : atmNO2);
		res = (res > atmPM10 ? res : atmPM10);
		return res;
	}
	const double& AirQualityData::getO3() const
	{
		for (auto mes : readings) {
			if (mes->getEType() == READINGTYPE::O3) {
				return mes->getValue();
			}
		}
		throw std::invalid_argument("measure not in database");
	}
	const double& AirQualityData::getSO2() const
	{
		for (auto mes : readings) {
			if (mes->getEType() == READINGTYPE::SO2) {
				return mes->getValue();
			}
		}
		throw std::invalid_argument("measure not in database");
	}
	const double& AirQualityData::getNO2() const
	{
		for (auto mes : readings) {
			if (mes->getEType() == READINGTYPE::NO2) {
				return mes->getValue();
			}
		}
		throw std::invalid_argument("measure not in database");
	}
	const double& AirQualityData::getPM10() const
	{
		for (auto mes : readings) {
			if (mes->getEType() == READINGTYPE::PM10) {
				return mes->getValue();
			}
		}
		throw std::invalid_argument("measure not in database");
	}
	bool AirQualityData::operator<(const unsigned long& time) const
	{
		return this->time<time;
	}
	bool AirQualityData::operator<(const AirQualityData& oData) const
	{
		return this->time<oData.time;
	}
}