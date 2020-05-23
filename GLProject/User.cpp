#include "User.h"
#include <string>

namespace users {
	bool User::operator<(const User& otherUser)const
	{
		return email<otherUser.email;
	}
	bool User::operator==(const User& otherUser)const
	{
		return email<otherUser.email;
	}
	User& User::operator=(const User& otherUser)
	{
		firstName = otherUser.firstName;
		lastName = otherUser.lastName;
		email = otherUser.email;
		password = otherUser.password;
		phoneNumber = otherUser.phoneNumber;


		return *this;
	}
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

    const std::string& User::getEmail() const {
        return email;
    }

     std::string User::toString() const {
        return email + ";" + firstName + ";" + lastName + ";" + password + ";" + phoneNumber;
    }

}
