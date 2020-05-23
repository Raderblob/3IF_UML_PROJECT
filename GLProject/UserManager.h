#pragma once
#include <set>
#include <map>
#include "User.h"
class UserManager
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- Méthodes publiques




	int addUser(const users::User* user);

	const users::User* tryLogin(const std::string& login, const std::string& password)const;

	int tryLogout(const users::User& user)const;

	int saveUsers();



	//------------------------------------------------- Surcharge d'opérateurs

	//-------------------------------------------- Constructeurs - destructeur
	UserManager();//load users from .txt


	virtual ~UserManager();

	//------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	std::map<std::string,const users::User*> userList;

};

