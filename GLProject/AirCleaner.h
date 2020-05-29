#pragma once
#include <string>
#include "Coordinate.h"
class AirCleaner
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques






    std::string toString()const;


	//------------------------------------------------- Surcharge d'opérateurs

	//-------------------------------------------- Constructeurs - destructeur
	AirCleaner(const std::string& aCID, const std::string& descr);

	virtual ~AirCleaner();

	//------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	std::string airCleanerId;
	std::string description;
	bool activated;
	data::Coordinate position;
	unsigned long time;
};
