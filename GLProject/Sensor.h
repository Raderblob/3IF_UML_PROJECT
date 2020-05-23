#pragma once
#include <string>
#include <list>
#include "AirQualityData.h"
namespace data {
	class Sensor
	{
		//----------------------------------------------------------------- PUBLIC
	public:
		//----------------------------------------------------- Méthodes publiques





        Sensor(const std::string &sensorId, double score, bool privateSensor, const std::string &description,
               const std::list<AirQualityData> &myData);



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
		std::list<AirQualityData> myData;
	};
}
