#pragma once
#include <string>
#include "Coordinate.h"
namespace data {
	class AirQualityData
	{
		//----------------------------------------------------------------- PUBLIC
	public:
		//----------------------------------------------------- Méthodes publiques









		//------------------------------------------------- Surcharge d'opérateurs

		//-------------------------------------------- Constructeurs - destructeur

		AirQualityData(const std::string& aID, const std::string& unit, const std::string& descr,const double& longi, const double& lat);

		virtual ~AirQualityData();

		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- Méthodes protégées

		//----------------------------------------------------- Attributs protégés
		std::string attributeId;
		std::string unit;
		std::string description;
		Coordinate position;
	};

}

