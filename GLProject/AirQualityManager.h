#pragma once
#include <list>
#include "UserManager.h"
#include "Sensor.h"
#include "AirCleaner.h"
class AirQualityManager
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques









	//------------------------------------------------- Surcharge d'opérateurs

	//-------------------------------------------- Constructeurs - destructeur
    AirQualityManager();

    virtual ~AirQualityManager();
    //------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	UserManager userManager;
	std::set<data::Sensor> sensors;
	std::set<AirCleaner> cleaners;
};

