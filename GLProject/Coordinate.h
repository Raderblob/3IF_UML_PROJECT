#pragma once
namespace data {
	class Coordinate
	{
		//----------------------------------------------------------------- PUBLIC
	public:
		//----------------------------------------------------- Méthodes publiques









		//------------------------------------------------- Surcharge d'opérateurs
		bool operator <(const Coordinate& otherCoord) const;
		bool operator ==(const Coordinate& otherCoord) const;
		Coordinate& operator = (const Coordinate& otherCoord);
		//-------------------------------------------- Constructeurs - destructeur

		Coordinate(const double& longd, const double& lat);
		Coordinate();

		virtual ~Coordinate();

		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- Méthodes protégées

		//----------------------------------------------------- Attributs protégés
		double longitude;
		double latitude;
	};
}
