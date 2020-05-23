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





        Sensor(const std::string &sensorId, double score, bool privateSensor, const std::string &description,
               const std::list<AirQualityData> &myData);



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
		std::list<AirQualityData> myData;
	};
}
