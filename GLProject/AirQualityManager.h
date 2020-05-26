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
	//----------------------------------------------------- M�thodes publiques



    void saveEverything()const;





	//------------------------------------------------- Surcharge d'op�rateurs

	//-------------------------------------------- Constructeurs - destructeur
    AirQualityManager();

    virtual ~AirQualityManager();
    //----------------------------------------------------- Public attributes
    UserManager userManager;
    //------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- M�thodes prot�g�es
    void loadSensors();
	void loadCleaners();
	void loadData();
	void saveSensors()const;
	void saveCleaners()const;
	void saveData() const;
	//----------------------------------------------------- Attributs prot�g�s
	std::map<std::string,data::Sensor*> sensors;
	std::map<std::string,AirCleaner*> cleaners;
	//std::vector<data::AirQualityData*> data;
};

