#include "Coordinate.h"
namespace data {
	bool Coordinate::operator<(const Coordinate& otherCoord) const
	{
		if (latitude == otherCoord.latitude) {
			return longitude < otherCoord.longitude;
		}
		return latitude < otherCoord.latitude;
	}
	bool Coordinate::operator==(const Coordinate& otherCoord) const
	{
		return longitude == otherCoord.longitude && latitude==otherCoord.latitude;
	}
	Coordinate& Coordinate::operator=(const Coordinate& otherCoord)
	{
		longitude = otherCoord.longitude;
		latitude = otherCoord.latitude;
		return *this;
	}
	Coordinate::Coordinate(const double& longd, const double& lat)
	{
		longitude = longd;
		latitude = lat;
	}

	Coordinate::Coordinate()
	{
		longitude = 0;
		latitude = 0;
	}
	Coordinate::~Coordinate()
	{
	}

    std::string Coordinate::toString() const {
        return std::to_string( longitude) + ";" + std::to_string( latitude);
    }
}