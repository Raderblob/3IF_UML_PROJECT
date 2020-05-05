#pragma once
namespace data {
	class Coordinate
	{
		//----------------------------------------------------------------- PUBLIC
	public:
		//----------------------------------------------------- M�thodes publiques









		//------------------------------------------------- Surcharge d'op�rateurs

		//-------------------------------------------- Constructeurs - destructeur

		Coordinate(const double& longd, const double& lat);
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
