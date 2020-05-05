#include "CompanyEmployee.h"

CompanyEmployee::CompanyEmployee(const std::string& cId, const std::string& cName, const double& aQLevel, AirQualityManager& myManager, const std::string& fName, const std::string& lName, const std::string& mail, const std::string& passw, const std::string& pNumber):User(fName,lName,mail,passw,pNumber)
{
	companyId = cId;
	companyName = cName;
	airQualityLevel = aQLevel;
	manager = &myManager;
}
