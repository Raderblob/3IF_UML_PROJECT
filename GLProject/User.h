#pragma once
#include <string>
namespace users {
	class User
	{
		//----------------------------------------------------------------- PUBLIC
	public:
		//----------------------------------------------------- M�thodes publiques

		int logOut();








		//------------------------------------------------- Surcharge d'op�rateurs
		bool operator <(const User& otherUser) const;
		bool operator ==(const User& otherUser) const;
		User& operator = (const User& otherUser);
		//-------------------------------------------- Constructeurs - destructeur

		User(const std::string& fName, const std::string& lName, const std::string& mail, const std::string& passw, const std::string& pNumber);

		virtual ~User();

		//------------------------------------------------------------------ PRIVE
	protected:
		//----------------------------------------------------- M�thodes prot�g�es

		//----------------------------------------------------- Attributs prot�g�s
		std::string firstName;
		std::string lastName;
		std::string email;
		std::string password;
		std::string phoneNumber;

	};
}
