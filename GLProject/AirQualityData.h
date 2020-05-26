#pragma once
#include <string>


namespace data {
	class Sensor;
	class AirQualityData
	{
		//----------------------------------------------------------------- PUBLIC
	public:
		//----------------------------------------------------- M�thodes publiques




        std::string toString()const;




		//------------------------------------------------- Surcharge d'op�rateurs

		//-------------------------------------------- Constructeurs - destructeur

		AirQualityData(const int& aID, const std::string& unit, const std::string& descr);

		virtual ~AirQualityData();

		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- M�thodes prot�g�es

		//----------------------------------------------------- Attributs prot�g�s
		int attributeId;
		std::string unit;
		std::string description;
		data::Sensor* mySensor;
	};

}

