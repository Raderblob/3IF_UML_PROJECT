#pragma once
#include <string>

class AirCleaner
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques









	//------------------------------------------------- Surcharge d'op�rateurs

	//-------------------------------------------- Constructeurs - destructeur
	AirCleaner(const std::string& aCID, const std::string& descr);

	virtual ~AirCleaner();

	//------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
	std::string airCleanerId;
	std::string description;
	bool activated;
};
