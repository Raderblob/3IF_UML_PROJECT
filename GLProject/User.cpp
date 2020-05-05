#include "User.h"
#include <string>


User::User(const std::string& fName, const std::string& lName, const std::string& mail, const std::string& passw, const std::string& pNumber)
{
	firstName = fName;
	lastName = lName;
	email = mail;
	password = passw;
	phoneNumber = pNumber;
}

int User::logOut()
{
	return 0;
}



User::~User()
{
}
