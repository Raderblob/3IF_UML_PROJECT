#include "UserManager.h"


UserManager::UserManager()
{

}

UserManager::~UserManager()
{
    //TODO Delete al users
}

int UserManager::saveUsers() {

    return 0;
}

int UserManager::addUser(const users::User * user) {
    return userList.insert({user->getEmail(),user}).second;
}

const users::User* UserManager::tryLogin(const std::string& login, const std::string& password)const {
    auto it = userList.find(login);

    if(it != userList.end()){
        return (it->second);
    }
    return nullptr;
}

int UserManager::tryLogout(const users::User &user) const {
    return 0;
}
