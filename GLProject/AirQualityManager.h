#pragma once
#include <list>
#include "UserManager.h"
#include "Sensor.h"
#include "AirCleaner.h"
class AirQualityManager
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques









	//------------------------------------------------- Surcharge d'op�rateurs

	//-------------------------------------------- Constructeurs - destructeur
    AirQualityManager();

    virtual ~AirQualityManager();
    //------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
	UserManager userManager;
	std::set<data::Sensor> sensors;
	std::set<AirCleaner> cleaners;
};

