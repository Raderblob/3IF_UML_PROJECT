#pragma once
#include <string>
#include "Coordinate.h"
class AirCleaner
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques






    std::string toString()const;


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
	data::Coordinate position;
	unsigned long time;
};
