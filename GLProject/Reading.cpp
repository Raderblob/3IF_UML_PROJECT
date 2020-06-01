#include "Reading.h"
#include <stdexcept>
#include <iostream>
namespace data {
	std::string Reading::getType() const
	{
		switch (type)
		{
		case data::READINGTYPE::O3:
			return "O3";
			break;
		case data::READINGTYPE::NO2:
			return "NO2";
			break;
		case data::READINGTYPE::SO2:
			return "SO2";
			break;
		case data::READINGTYPE::PM10:
			return "PM10";
			break;
		default:
			throw std::invalid_argument("type not in enum");
			break;
		}
	}
	const double& Reading::getValue() const
	{
		return value;
	}
	const READINGTYPE& Reading::getEType() const
	{
		return type;
	}
	data::Reading::Reading(const std::string& type, const double& val)
	{
#ifdef DEBUG
		std::cout << "Constructor for Reading" << std::endl;
#endif // DEBUG
		if (type == "O3") {
			this->type = READINGTYPE::O3;
		}
		else if(type == "NO2")
		{
			this->type = READINGTYPE::NO2;
		}
		else if (type == "SO2") {
			this->type = READINGTYPE::SO2;
		}
		else if (type == "PM10") {
			this->type = READINGTYPE::PM10;
		}
		else {
			throw std::invalid_argument("Reading type not Valid");
		}
		value = val;
	}

}
