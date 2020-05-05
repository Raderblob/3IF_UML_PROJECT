#include "Coordinate.h"
namespace data {
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
}