#include "Reading.h"
#include <stdexcept>
namespace data {
	const READINGTYPE& Reading::getType() const
	{
		return type;
	}
	const double& Reading::getValue() const
	{
		return value;
	}
	data::Reading::Reading(const std::string& type, const double& val)
	{
		if (type == "O3") {
			this->type = READINGTYPE::O3;
		}
		else if(type == "NO2")
		{
			this->type = READINGTYPE::NO2;
		}
		else if (type == "SO2") {
			this->type = READINGTYPE::NO2;
		}
		else if (type == "PM10") {
			this->type = READINGTYPE::NO2;
		}
		else {
			throw std::invalid_argument("Reading type not Valid");
		}
		value = val;
	}

}
