#pragma once
#include <string>
#include "Coordinate.h"
namespace data {
	class AirQualityData
	{
		//----------------------------------------------------------------- PUBLIC
	public:
		//----------------------------------------------------- M�thodes publiques









		//------------------------------------------------- Surcharge d'op�rateurs

		//-------------------------------------------- Constructeurs - destructeur

		AirQualityData(const std::string& aID, const std::string& unit, const std::string& descr,const double& longi, const double& lat);

		virtual ~AirQualityData();

		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- M�thodes prot�g�es

		//----------------------------------------------------- Attributs prot�g�s
		std::string attributeId;
		std::string unit;
		std::string description;
		Coordinate position;
	};

}

