#include "AirQualityData.h"
namespace data {
	AirQualityData::AirQualityData(const int& aID, const std::string& u, const std::string& descr)
	{
		attributeId = aID;
		unit = u;
		description = descr;

	}
	AirQualityData::~AirQualityData()
	{
	}

    std::string AirQualityData::toString() const {
	    std::string res = std::to_string(attributeId) + ";" + unit + ";" + description;

        return res;
    }
}