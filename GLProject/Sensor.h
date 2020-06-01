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
		//----------------------------------------------------- Méthodes publiques



		/**
		* Returns string with basic contents of sensor
		*
		*
		* @return String with contents of sensor
		*/
        std::string toString()const;

		/**
		* Adds the data to the Sensor
		* @param nData cannot be null
		*
		* 
		*/
		void addData(AirQualityData* nData);

		/**
		* returns Data from sensor
		* 
		*
		* @return reference of vector to all data that the sensor collected
		*/
		const std::vector<AirQualityData*>& getData()const;


		///Returns Id of sensor
		const std::string& getId()const;


		///Returns Positions of sensor
		const Coordinate& getPosition()const;

        //------------------------------------------------- Surcharge d'opérateurs

		//-------------------------------------------- Constructeurs - destructeur
		

		/**
		* returns Data from sensor
		* @param  sensorID Sensor ID of sensor
		* @param score score of sensor (Not implemented)
		* @param privateSensor (Not implemented)
		* @param aCoord Position of Sensor
		* @param desc (Not implemented)
		*
		* @return reference of vector to all data that the sensor collected
		*/
		Sensor(const std::string& sensorID, const int& score, const bool& privateSensor, const Coordinate& aCoord, const std::string descr);

		///Not implemented
		Sensor(const Sensor& aSensor);

		///Destructor for Sensor
		virtual ~Sensor();

		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- Méthodes protégées

		//----------------------------------------------------- Attributs protégés
		std::string sensorID;
		double score;
		bool privateSensor;
		Coordinate myPosition;
		std::string description;
		std::vector<AirQualityData*> myData;
	};
}
