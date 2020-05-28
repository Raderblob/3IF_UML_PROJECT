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

		AirQualityData(const std::string& unit, const std::string& descr,const data::Sensor* nSensor);

		virtual ~AirQualityData();

		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- Méthodes protégées

		//----------------------------------------------------- Attributs protégés
		int attributeId;
		std::string unit;
		std::string description;
		const data::Sensor* mySensor;
	};

}

