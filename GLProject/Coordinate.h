#pragma once
namespace data {
	class Coordinate
	{
		//----------------------------------------------------------------- PUBLIC
	public:
		//----------------------------------------------------- Méthodes publiques









		//------------------------------------------------- Surcharge d'opérateurs

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
