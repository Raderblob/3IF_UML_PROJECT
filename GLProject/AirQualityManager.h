#pragma once
#include "UserManager.h"
#include "AirCleaner.h"
#include "Sensor.h"
#include "QuadTree.h"
class AirQualityManager
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques



    void saveEverything()const;
	void loadEverything();
	double getMeanAirQuality(const data::Coordinate& centerPoint, const double& totalWidth)const;
	double getMeanAirQualityWithDate(const data::Coordinate& centerPoint, const double& totalWidth , const std::string& startTime , const std::string& endTime)const;
	double getMeanAirQualityWithDate(const data::Coordinate& centerPoint, const double& totalWidth, const unsigned long& startTime, const unsigned long& endTime)const;
	const std::map<std::string, AirCleaner*>& getCleaners()const;
	double getAreaOfEffectOfCleaner(const AirCleaner& cl,const double& step,const bool& ratio,double maxOrRatio)const;
	void print();

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
	std::map<std::string,AirCleaner*> cleaners;
	std::map<std::string,data::Sensor*> sensors;
	std::map<data::Coordinate, std::vector<data::Sensor*>> regionSensorLists;
	data::tree::QuadTree* sensorTree;
};

