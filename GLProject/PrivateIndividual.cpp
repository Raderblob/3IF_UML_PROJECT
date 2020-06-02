#include "PrivateIndividual.h"
namespace users {
  PrivateIndividual::PrivateIndividual(Sensor& sensor, const std::string& fName, const std::string& lName, const std::string& mail, const std::string& passw, const std::string& pNumber) :User(fName, lName, mail, passw, pNumber)
	{
		mySensor = &sensor;
	}

}