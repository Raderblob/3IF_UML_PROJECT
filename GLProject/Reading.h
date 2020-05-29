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
		//----------------------------------------------------- M�thodes publiques

		const READINGTYPE& getType()const;
		const double& getValue()const;
		

		//------------------------------------------------- Surcharge d'op�rateurs

		//-------------------------------------------- Constructeurs - destructeur
		Reading(const std::string& type, const double& val);

		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- M�thodes prot�g�es
		READINGTYPE type;
		double value;
		//----------------------------------------------------- Attributs prot�g�s
	};
}

