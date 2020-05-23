#include "AirCleaner.h"

AirCleaner::AirCleaner(const std::string& aCID, const std::string& descr)
{
	airCleanerId = aCID;
	description = descr;
	activated = false;
}

AirCleaner::~AirCleaner()
{
}

std::string AirCleaner::toString() const {
    return airCleanerId + ";" + description + ";" + (activated ? "1" : "0");
}
