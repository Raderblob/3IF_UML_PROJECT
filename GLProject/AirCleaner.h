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
	AirCleaner(const std::string& aCID,const data::Coordinate mPos, const unsigned long& t1, unsigned long t2);

	virtual ~AirCleaner();

	//------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	unsigned long time1, time2;
	std::string airCleanerId;
	bool activated;
	data::Coordinate position;
};
