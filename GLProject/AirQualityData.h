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
		//----------------------------------------------------- M�thodes publiques




        std::string toString()const;
		const unsigned long& getTime()const;
		void addReading(Reading* nReading);
		const std::string& getSensorId()const;
		int getAtmo()const;
		const double& getO3()const;
		const double& getSO2()const;
		const double& getNO2()const;
		const double& getPM10()const;


		//------------------------------------------------- Surcharge d'op�rateurs
		bool operator <(const unsigned long& time) const;
		bool operator <(const AirQualityData& oData) const;
		//-------------------------------------------- Constructeurs - destructeur

		AirQualityData( const unsigned long& mTime,const data::Sensor* nSensor,Reading* mReading);

		virtual ~AirQualityData();

		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- M�thodes prot�g�es

		//----------------------------------------------------- Attributs prot�g�s
		std::vector<Reading*> readings;
		int attributeId;
		unsigned long time;
		const data::Sensor* mySensor;

	};

}

