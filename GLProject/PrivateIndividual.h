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
		//----------------------------------------------------- M�thodes publiques









		//------------------------------------------------- Surcharge d'op�rateurs

		//-------------------------------------------- Constructeurs - destructeur
		PrivateIndividual(Sensor& sensor, const std::string& fName, const std::string& lName, const std::string& mail, const std::string& passw, const std::string& pNumber);


		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- M�thodes prot�g�es

		//----------------------------------------------------- Attributs prot�g�s
		data::Sensor* mySensor;

	};
}

