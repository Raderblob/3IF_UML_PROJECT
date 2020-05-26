#pragma once
#include <string>
#include "AirQualityData.h"
#include <vector>
namespace data {
	class Sensor
	{
		//----------------------------------------------------------------- PUBLIC
	public:
		//----------------------------------------------------- Méthodes publiques




        std::string toString()const;



        //------------------------------------------------- Surcharge d'opérateurs

		//-------------------------------------------- Constructeurs - destructeur



		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- Méthodes protégées

		//----------------------------------------------------- Attributs protégés
		std::string sensorID;
		double score;
		bool privateSensor;
		std::string description;
		std::vector<AirQualityData> myData;
	};
}
