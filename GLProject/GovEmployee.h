#pragma once
#include "User.h"
#include "AirQualityManager.h"
class GovEmployee :
	public User
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques

	







	//------------------------------------------------- Surcharge d'op�rateurs

	//-------------------------------------------- Constructeurs - destructeur

	GovEmployee(const std::string& govId, AirQualityManager& myManager, const std::string& fName, const std::string& lName, const std::string& mail, const std::string& passw, const std::string& pNumber);

	//------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
	std::string govId;
	AirQualityManager* manager;
};

