#pragma once
#include <string>
#include "AirQualityData.h"
#include <vector>
namespace data {
	class Sensor
	{
		//----------------------------------------------------------------- PUBLIC
	public:
		//----------------------------------------------------- M�thodes publiques




        std::string toString()const;



        //------------------------------------------------- Surcharge d'op�rateurs

		//-------------------------------------------- Constructeurs - destructeur



		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- M�thodes prot�g�es

		//----------------------------------------------------- Attributs prot�g�s
		std::string sensorID;
		double score;
		bool privateSensor;
		std::string description;
		std::vector<AirQualityData> myData;
	};
}
