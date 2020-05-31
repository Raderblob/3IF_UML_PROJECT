#include "AirCleaner.h"
AirCleaner::AirCleaner(const std::string& aCID,  const data::Coordinate mPos, const unsigned long& t1, unsigned long t2)
{
	airCleanerId = aCID;
	time1 = t1;
	time2 = t2;
	activated = false;
	position = mPos;
}

AirCleaner::~AirCleaner()
{
}

std::string AirCleaner::toString() const {
    return airCleanerId + ";" +  position.toString() +";" + std::to_string(time1) + ";" + std::to_string(time2) + ";" + (activated ? "1" : "0");
}

const data::Coordinate& AirCleaner::getPosition() const
{
	return position;
}

const unsigned long& AirCleaner::getTime1() const
{
	return time1;
}

const unsigned long& AirCleaner::getTime2() const
{
	return time2;
}
