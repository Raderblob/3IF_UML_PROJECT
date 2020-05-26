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

		AirQualityData(const int& aID, const std::string& unit, const std::string& descr);

		virtual ~AirQualityData();

		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- Méthodes protégées

		//----------------------------------------------------- Attributs protégés
		int attributeId;
		std::string unit;
		std::string description;
		data::Sensor* mySensor;
	};

}

