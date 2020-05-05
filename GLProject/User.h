#pragma once
#include <string>
namespace users {
	class User
	{
		//----------------------------------------------------------------- PUBLIC
	public:
		//----------------------------------------------------- Méthodes publiques

		int logOut();








		//------------------------------------------------- Surcharge d'opérateurs
		bool operator <(const User& otherUser) const;
		bool operator ==(const User& otherUser) const;
		User& operator = (const User& otherUser);
		//-------------------------------------------- Constructeurs - destructeur

		User(const std::string& fName, const std::string& lName, const std::string& mail, const std::string& passw, const std::string& pNumber);

		virtual ~User();

		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- Méthodes protégées

		//----------------------------------------------------- Attributs protégés
		std::string firstName;
		std::string lastName;
		std::string email;
		std::string password;
		std::string phoneNumber;

	};
}
