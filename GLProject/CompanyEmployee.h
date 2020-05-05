#pragma once
#include "User.h"
#include "AirQualityManager.h"
namespace users {
	class CompanyEmployee :
		public User
	{
		//----------------------------------------------------------------- PUBLIC
	public:
		//----------------------------------------------------- Méthodes publiques









		//------------------------------------------------- Surcharge d'opérateurs

		//-------------------------------------------- Constructeurs - destructeur
		CompanyEmployee(const std::string& cId, const std::string& cName, const double& aQLevel, AirQualityManager& myManager, const std::string& fName, const std::string& lName, const std::string& mail, const std::string& passw, const std::string& pNumber);


		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- Méthodes protégées

		//----------------------------------------------------- Attributs protégés
		std::string companyId;
		std::string companyName;
		double airQualityLevel;
		AirQualityManager* manager;
	};
}

