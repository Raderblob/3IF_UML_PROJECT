#pragma once
#include <map>
#include "User.h"
class UserManager
{
	//----------------------------------------------------------------- PUBLIC
public:
	//----------------------------------------------------- M�thodes publiques



	/**
	* Adds User to the UserList
	*
	* @param User pointer, Cannot be null
	* @return 1 if correct
	*/
	int addUser(const users::User* user);


	///Prints contents into cout
	void showContents()const;

	const users::User* tryLogin(const std::string& login, const std::string& password)const;

	int tryLogout(const users::User& user)const;

	int saveUsers() const;
    void loadUsers();


	//------------------------------------------------- Surcharge d'op�rateurs

	//-------------------------------------------- Constructeurs - destructeur
	UserManager();//load users from .txt


	virtual ~UserManager();

	//------------------------------------------------------------------ PRIVE
protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
	std::map<std::string,const users::User*> userList;

};

