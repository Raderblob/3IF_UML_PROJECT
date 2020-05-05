#pragma once
#include <string>
#include <list>
#include "AirQualityData.h"
namespace data {
	class Sensor
	{
		//----------------------------------------------------------------- PUBLIC
	public:
		//----------------------------------------------------- M�thodes publiques









		//------------------------------------------------- Surcharge d'op�rateurs

		//-------------------------------------------- Constructeurs - destructeur



		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- M�thodes prot�g�es

		//----------------------------------------------------- Attributs prot�g�s
		std::string sensorID;
		std::string description;
		std::list<AirQualityData> myData;
	};
}
