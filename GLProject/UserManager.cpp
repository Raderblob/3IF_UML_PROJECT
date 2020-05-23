#include "UserManager.h"
#include "Util.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
UserManager::UserManager()
{
    fstream file;
    file.open("dataset/users.csv",ios::in);
    if(file.is_open()) {
        while(!file.eof()){
            string str;
            file>>str;
            vector<string> vec = Util::splitString(str,';');
            if(vec.size()==6) {
                userList.insert({vec.at(0), new users::User(vec.at(1), vec.at(2), vec.at(0), vec.at(3), vec.at(4))});
            }
        }
    }
    file.close();
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
    fstream file;
    file.open("dataset/users.csv",ios::out);

    if(file.is_open()) {
        auto it = userList.begin();
        while (it != userList.end()) {
            string str = it->second->toString();
            file<<str<<";"<<endl;

            it = ++it;
        }
    }
    file.close();
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
