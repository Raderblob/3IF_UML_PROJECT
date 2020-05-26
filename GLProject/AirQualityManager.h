#pragma once
#include <list>
#include "UserManager.h"
#include <vector>
#include <map>
namespace data {
	class Sensor;
	class AirQualityData;
}
class AirCleaner;

class UserManager;
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
    void loadSensors();
	void loadCleaners();
	void loadData();
	void saveSensors()const;
	void saveCleaners()const;
	void saveData() const;
	//----------------------------------------------------- Attributs protégés
	std::map<std::string,data::Sensor*> sensors;
	std::map<std::string,AirCleaner*> cleaners;
	//std::vector<data::AirQualityData*> data;
};

