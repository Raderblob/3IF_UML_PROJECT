#pragma once
#include <string>
#include "Reading.h"
#include <vector>

namespace data {
	class Sensor;
	class AirQualityData
	{
		//----------------------------------------------------------------- PUBLIC
	public:
		//----------------------------------------------------- Méthodes publiques



		///Returns String of Object
        std::string toString()const;

		/// Returns time that the daat was acquired
		const unsigned long& getTime()const;

		/**
		* Adds a Reading to Data
		*
		* @param nReading Reading to be added
		*
		*
		*/
		void addReading(Reading* nReading);

		///Returns Id of the sensor
		const std::string& getSensorId()const;

		///Returns Atmo of the sensor
		int getAtmo()const;

		///Returns O3 of the sensor
		const double& getO3()const;

		///Returns SO2 of the sensor
		const double& getSO2()const;

		///Returns NO2 of the sensor
		const double& getNO2()const;

		///Returns PM10 of the sensor
		const double& getPM10()const;


		//------------------------------------------------- Surcharge d'opérateurs
		bool operator <(const unsigned long& time) const;
		bool operator <(const AirQualityData& oData) const;
		//-------------------------------------------- Constructeurs - destructeur

		/**
		* Constructor for AirQualityData
		*
		* @param mTime Time the data was taken (seconds since 2020)
		* @param nSensor Sensor that took the data (Cannot be null)
		* @param mReading First Reading of the sensor
		*
		*/
		AirQualityData( const unsigned long& mTime,const data::Sensor* nSensor,Reading* mReading);

		///Destructor for the sensor
		virtual ~AirQualityData();

		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- Méthodes protégées

		//----------------------------------------------------- Attributs protégés
		std::vector<Reading*> readings;
		int attributeId;
		unsigned long time;
		const data::Sensor* mySensor;

	};

}

