#pragma once
#include <string>


namespace data {
	class Sensor;
	class AirQualityData
	{
		//----------------------------------------------------------------- PUBLIC
	public:
		//----------------------------------------------------- Méthodes publiques




        std::string toString()const;




		//------------------------------------------------- Surcharge d'opérateurs

		//-------------------------------------------- Constructeurs - destructeur

		AirQualityData(const std::string& unit, const std::string& descr,const data::Sensor* nSensor,const double& val);

		virtual ~AirQualityData();

		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- Méthodes protégées

		//----------------------------------------------------- Attributs protégés
		int attributeId;
		std::string unit;
		double value;
		unsigned long time;
		const data::Sensor* mySensor;
	};

}

