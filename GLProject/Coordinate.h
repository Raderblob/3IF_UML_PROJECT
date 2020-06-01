#pragma once

#include <string>

namespace data {
	class Coordinate
	{
		//----------------------------------------------------------------- PUBLIC
	public:
		//----------------------------------------------------- Méthodes publiques




		/// Returns string of Coordinate with longitude and latitude
        std::string toString()const;


		/// Returns Longitude
		const double& getLongitude()const;

		/// Returns Latitude
		const double& getLatitude()const;

		/// set Longitude
		void setLongitude(const double& l);

		/// set Latitude
		void setLatitude(const double& l);

		/**
		* Get Coordinates of Point rounded down into a grid
		*
		* @param gridSize Width and height of the grid
		*
		* @return Coordinate within grid
		*/
		Coordinate getGridCoords(const int& gridSize)const;

		/**
		* returns true if position inside Square
		*
		* @param squareTopLeft top left of square 
		* @param squareSize width and height of Square
		*
		* @return true if point inside square
		*/
		bool inSquare(const Coordinate& squareTopLeft, const double& squareSize)const;

		//------------------------------------------------- Surcharge d'opérateurs
		bool operator <(const Coordinate& otherCoord) const;
		bool operator ==(const Coordinate& otherCoord) const;
		Coordinate operator +(const Coordinate& otherCoord)const;
		Coordinate operator +(const double& translation)const;
		Coordinate operator -(const Coordinate& otherCoord)const;
		Coordinate operator -(const double& translation)const;
		Coordinate operator *(const double& mult)const;
		Coordinate operator /(const double& div)const;

		Coordinate& operator = (const Coordinate& otherCoord);
		//-------------------------------------------- Constructeurs - destructeur

		/**
		* Constructor for Coordinate
		*
		* @param longd longitude to be set
		* @param lat latitude to be set
		*
		* 
		*/
		Coordinate(const double& longd, const double& lat);

		/**
		* Constructor for Coordinate (copy)
		*
		* @param aCoord Coordinate to be copied
		*
		*
		*/
		Coordinate(const Coordinate& aCoord);

		///Default Constructor for Coordinate
		Coordinate();

		/// Destructor for Coordinate
		virtual ~Coordinate();

		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- Méthodes protégées

		//----------------------------------------------------- Attributs protégés
		double longitude;
		double latitude;
	};
}
