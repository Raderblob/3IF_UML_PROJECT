#pragma once

#include <string>

namespace data {
	class Coordinate
	{
		//----------------------------------------------------------------- PUBLIC
	public:
		//----------------------------------------------------- M�thodes publiques





        std::string toString()const;

		const double& getLongitude()const;
		const double& getLatitude()const;

		Coordinate getGridCoords(const int& gridSize)const;

		//------------------------------------------------- Surcharge d'op�rateurs
		bool operator <(const Coordinate& otherCoord) const;
		bool operator ==(const Coordinate& otherCoord) const;
		Coordinate operator +(const Coordinate& otherCoord)const;
		Coordinate operator -(const Coordinate& otherCoord)const;
		Coordinate operator *(const double& mult)const;
		Coordinate operator /(const double& div)const;

		Coordinate& operator = (const Coordinate& otherCoord);
		//-------------------------------------------- Constructeurs - destructeur

		Coordinate(const double& longd, const double& lat);
		Coordinate(const Coordinate& aCoord);
		Coordinate();

		virtual ~Coordinate();

		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- M�thodes prot�g�es

		//----------------------------------------------------- Attributs prot�g�s
		double longitude;
		double latitude;
	};
}
