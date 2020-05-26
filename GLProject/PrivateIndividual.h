#pragma once
#include "User.h"
namespace data {
	class Sensor;
}
namespace users {
	class PrivateIndividual :
		public User
	{
		//----------------------------------------------------------------- PUBLIC
	public:
		//----------------------------------------------------- Méthodes publiques









		//------------------------------------------------- Surcharge d'opérateurs

		//-------------------------------------------- Constructeurs - destructeur



		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- Méthodes protégées

		//----------------------------------------------------- Attributs protégés
		data::Sensor* mySensor;

	};
}

