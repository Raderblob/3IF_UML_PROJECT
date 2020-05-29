#pragma once
#include "UserManager.h"
#include "AirCleaner.h"
#include "Sensor.h"
class AirQualityManager
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques



    void saveEverything()const;
	void loadEverything();


	void print();

	//------------------------------------------------- Surcharge d'opérateurs

	//-------------------------------------------- Constructeurs - destructeur
    AirQualityManager();

    virtual ~AirQualityManager();
    //----------------------------------------------------- Public attributes
    UserManager userManager;
    //------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- Méthodes protégées
    void loadSensors();
	void loadCleaners();
	void loadData();
	void saveSensors()const;
	void saveCleaners()const;
	void saveData() const;
	//----------------------------------------------------- Attributs protégés
	std::map<std::string,AirCleaner*> cleaners;
	std::map<std::string,data::Sensor*> sensors;
	std::map<data::Coordinate, std::vector<data::Sensor*>> regionSensorLists;
};

