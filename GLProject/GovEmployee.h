#pragma once
#include "User.h"
class AirQualityManager;
namespace users {
	class GovEmployee :
		public User
	{
		//----------------------------------------------------------------- PUBLIC
	public:
		//----------------------------------------------------- Méthodes publiques









		//------------------------------------------------- Surcharge d'opérateurs

		//-------------------------------------------- Constructeurs - destructeur

		GovEmployee(const std::string& gId, AirQualityManager& myManager, const std::string& fName, const std::string& lName, const std::string& mail, const std::string& passw, const std::string& pNumber);

		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- Méthodes protégées

		//----------------------------------------------------- Attributs protégés
		std::string govId;
		AirQualityManager* manager;
	};

}