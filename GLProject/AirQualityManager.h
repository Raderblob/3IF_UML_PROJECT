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



    void saveEverything()const;





	//------------------------------------------------- Surcharge d'opérateurs

	//-------------------------------------------- Constructeurs - destructeur
    AirQualityManager();

    virtual ~AirQualityManager();
    //----------------------------------------------------- Public attributes
    UserManager userManager;
    //------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- Méthodes protégées
    void loadSensors()const;
	void loadCleaners()const;
	//----------------------------------------------------- Attributs protégés
	std::map<std::string,data::Sensor*> sensors;
	std::set<std::string,AirCleaner*> cleaners;
};

