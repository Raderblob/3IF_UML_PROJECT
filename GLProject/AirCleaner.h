#pragma once
#include <string>
#include "Coordinate.h"
class AirCleaner
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques





	///ToString for AirCleaner
    std::string toString()const;

	///Returns Position of AirCleaner
	const data::Coordinate& getPosition()const;

	///Returns ActivationTime of AirCleaner (In seconds since 2020)
	const unsigned long& getTime1()const;

	///Returns deactivation of AirCleaner (In seconds since 2020)
	const unsigned long& getTime2()const;

	//------------------------------------------------- Surcharge d'opérateurs

	//-------------------------------------------- Constructeurs - destructeur

		/**
		* Constructor for AirCleaner
		*
		* @param aCID ID of Cleaner
		* @param mPos Position of Cleaner
		* @param t1 activation time of Cleaner (seconds since 2020)
		* @param t2 deactivation time of Cleaner (seconds since 2020)
		*
		*/
	AirCleaner(const std::string& aCID,const data::Coordinate mPos, const unsigned long& t1, unsigned long t2);

	///Destructor of AirCleaner
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
