#pragma once
#include <string>
#include "AirQualityData.h"
#include "Coordinate.h"
#include <vector>
namespace data {
	class Sensor
	{
		//----------------------------------------------------------------- PUBLIC
	public:
		//----------------------------------------------------- M�thodes publiques




        std::string toString()const;

		void addData(AirQualityData* nData);
		const std::vector<AirQualityData*>& getData()const;

		const std::string& getId()const;
		const Coordinate& getPosition()const;

        //------------------------------------------------- Surcharge d'op�rateurs

		//-------------------------------------------- Constructeurs - destructeur
		
		Sensor(const std::string& sensorID, const int& score, const bool& privateSensor, const Coordinate& aCoord, const std::string descr);
		Sensor(const Sensor& aSensor);

		virtual ~Sensor();

		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- M�thodes prot�g�es

		//----------------------------------------------------- Attributs prot�g�s
		std::string sensorID;
		double score;
		bool privateSensor;
		Coordinate myPosition;
		std::string description;
		std::vector<AirQualityData*> myData;
	};
}
