#include "GovEmployee.h"
namespace users {
	GovEmployee::GovEmployee(const std::string& gId, AirQualityManager& myManager, const std::string& fName, const std::string& lName, const std::string& mail, const std::string& passw, const std::string& pNumber) :User(fName, lName, mail, passw, pNumber)
	{
		govId = gId;
		manager = &myManager;
	}
}