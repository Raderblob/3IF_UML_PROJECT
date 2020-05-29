#pragma once
#include <string>
namespace data {
	enum class READINGTYPE
	{
		O3,NO2,SO2,PM10
	};

	class Reading
	{
		//----------------------------------------------------------------- PUBLIC
	public:
		//----------------------------------------------------- Méthodes publiques

		const READINGTYPE& getType()const;
		const double& getValue()const;
		

		//------------------------------------------------- Surcharge d'opérateurs

		//-------------------------------------------- Constructeurs - destructeur
		Reading(const std::string& type, const double& val);

		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- Méthodes protégées
		READINGTYPE type;
		double value;
		//----------------------------------------------------- Attributs protégés
	};
}

