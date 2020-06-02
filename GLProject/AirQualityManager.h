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



    /// not implemented
    void saveEverything()const;

	/**
	* Loads all the information from csv files
	*
	* @see loadSensors
	* @see loadCleaners
	* @see loadData
	* 
	*/
	void loadEverything();

	/**
	* Get mean air quality in a XxX square 
	* @see loadEverything required before
	*
	* @param centerPoint Center of the grid of the grid
	* @param totalWidth width and height of the square
	* 
	* @return The mean air quality as a double
	*/
	double getMeanAirQuality(const data::Coordinate& centerPoint, const double& totalWidth)const;

	/**
	* Get mean air quality in a XxX square between two dates
	* @see loadEverything required before
	*
	* @param centerPoint Center of the grid
	* @param totalWidth width and height of the square
	* @param startTime start date Needs to be in correct format
	* @param endTime end date Needs to be in correct format
	*
	* @return The mean air quality as a double
	*/
	double getMeanAirQualityWithDate(const data::Coordinate& centerPoint, const double& totalWidth , const std::string& startTime , const std::string& endTime)const;

	/**
	* Get mean air quality in a XxX square between two dates
	* @see loadEverything required before
	*
	* @param centerPoint Center of the grid
	* @param totalWidth width and height of the square
	* @param startTime start date as a long (number of seconds since 2020)
	* @param endTime end date as a long (number of seconds since 2020)
	*
	* @return The mean air quality as a double
	*/
	double getMeanAirQualityWithDate(const data::Coordinate& centerPoint, const double& totalWidth, const unsigned long& startTime, const unsigned long& endTime)const;

	/**
	* Returns map of airCleaners
	*
	*
	* @return reference to the map of airCleaners
	*/
	const std::map<std::string, AirCleaner*>& getCleaners()const;

	/**
	* Get Area of effect of a certain cleaner as a square with a center point
	* @see loadEverything required before
	*
	* @param cl The air cleaner to check the area of
	* @param step The step (precision) of the check (needs to be >0)
	* @param ratio ratio is true if the check is going to be ratio based
	* @param maxOrRatio if ratio == true then this is a max average pollution of the zone. If ratio == false then this is a ratio limit between when the aiCleaner is on and off
	* 
	*
	* @return the width of the square in km (The center is the AirCleaners)
	*/
	double getAreaOfEffectOfCleaner(const AirCleaner& cl,const double& step,const bool& ratio,double maxOrRatio)const;

	/// Prints the contents stored in memory
	void print();

	//------------------------------------------------- Surcharge d'op�rateurs

	//-------------------------------------------- Constructeurs - destructeur

    /// Constructor for AirQualityManager
    AirQualityManager();

	/// Destructor for AirQualityManager
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
	std::map<data::Coordinate, std::vector<data::Sensor*> > regionSensorLists;
	data::tree::QuadTree* sensorTree;
};

