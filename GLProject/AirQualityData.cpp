#include "AirQualityData.h"
namespace data {
	AirQualityData::AirQualityData(const std::string& aID, const std::string& u, const std::string& descr, const double& longi, const double& lat)
	{
		attributeId = aID;
		unit = u;
		description = descr;
		position = Coordinate(longi, lat);

	}
	AirQualityData::~AirQualityData()
	{
	}
}