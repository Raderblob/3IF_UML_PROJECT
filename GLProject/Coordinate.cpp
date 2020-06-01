#include "Coordinate.h"
#include <iostream>
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
	Coordinate Coordinate::operator+(const Coordinate& otherCoord) const
	{
		return(Coordinate(longitude + otherCoord.longitude, latitude + otherCoord.latitude));
	}
	Coordinate Coordinate::operator+(const double& translation) const
	{
		return Coordinate(longitude+translation,latitude+translation);
	}
	Coordinate Coordinate::operator-(const Coordinate& otherCoord) const
	{
		return(Coordinate(longitude - otherCoord.longitude, latitude - otherCoord.latitude));
	}
	Coordinate Coordinate::operator-(const double& translation) const
	{
		return Coordinate(longitude-translation,latitude-translation);
	}
	Coordinate Coordinate::operator/(const double& div) const
	{
		return(Coordinate(longitude/div, latitude/div));
	}
	Coordinate Coordinate::operator*(const double& mult) const
	{
		return(Coordinate(longitude * mult, latitude * mult));
	}
	Coordinate& Coordinate::operator=(const Coordinate& otherCoord)
	{
		longitude = otherCoord.longitude;
		latitude = otherCoord.latitude;
		return *this;
	}
	Coordinate::Coordinate(const double& longd, const double& lat)
	{
#ifdef DEBUG
		std::cout << "Constructor for Coordinate" << std::endl;
#endif // DEBUG
		longitude = longd;
		latitude = lat;
	}

	Coordinate::Coordinate(const Coordinate& aCoord)
	{
#ifdef DEBUG
		std::cout << "Constructor(copy) for Coordinate" << std::endl;
#endif // DEBUG
		longitude = aCoord.longitude;
		latitude = aCoord.latitude;
	}

	Coordinate::Coordinate()
	{
#ifdef DEBUG
		std::cout << "Constructor(Default) for Coordinate" << std::endl;
#endif // DEBUG
		longitude = 0;
		latitude = 0;
	}
	Coordinate::~Coordinate()
	{
#ifdef DEBUG
		std::cout << "Destructor for Coordinate" << std::endl;
#endif // DEBUG
	}

    std::string Coordinate::toString() const {
        return std::to_string( longitude) + ";" + std::to_string( latitude);
    }
	const double& Coordinate::getLongitude() const
	{
		return longitude;
	}
	const double& Coordinate::getLatitude() const
	{
		return latitude;
	}
	void Coordinate::setLongitude(const double& l)
	{
		longitude = l;
	}
	void Coordinate::setLatitude(const double& l)
	{
		latitude = l;
	}
	Coordinate Coordinate::getGridCoords(const int& gridSize) const
	{
		return Coordinate(int(longitude/gridSize),int(latitude/gridSize));
	}
	bool Coordinate::inSquare(const Coordinate& squareTopLeft, const double& squareSize)const
	{
		Coordinate squareBottomRight = squareTopLeft + squareSize;
		return (longitude>=squareTopLeft.longitude && latitude>=squareTopLeft.latitude && longitude<squareBottomRight.longitude&&latitude<squareBottomRight.latitude);
	}
}