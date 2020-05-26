#include "UserManager.h"
#include "Util.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include<string>
using namespace std;
UserManager::UserManager()
{

}

UserManager::~UserManager()
{
    std::cout<<"Deleting userList" <<std::endl;
    auto it = userList.begin();
    while(it!=userList.end()){
        std::cout<<it->second->getEmail()<<std::endl;
        delete it->second;
        it = ++it;
    }
}

int UserManager::saveUsers() const{
    return 0;
}

int UserManager::addUser(const users::User * user) {
    bool res = userList.insert({user->getEmail(),user}).second;
    if(!res){
        delete user;
    }

    return res;
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

void UserManager::showContents() const {
    std::cout<<"All users: "<<std::endl;
    auto it = userList.begin();
    while(it!=userList.end()){
        std::cout<<it->second->getEmail()<<std::endl;
        it = ++it;
    }
}

void UserManager::loadUsers() {

}
