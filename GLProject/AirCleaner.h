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
	AirCleaner(const std::string& aCID,const data::Coordinate mPos, const unsigned long& t1, unsigned long t2);

	virtual ~AirCleaner();

	//------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
	unsigned long time1, time2;
	std::string airCleanerId;
	bool activated;
	data::Coordinate position;
};
