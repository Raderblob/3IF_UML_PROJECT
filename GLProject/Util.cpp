//
// Created by richard on 23/05/2020.
//

#include "Util.h"
#include <sstream>
#include <iostream>
static std::chrono::steady_clock::time_point startTime;


std::vector<std::string> Util::splitString(const std::string &str, const char &del) {
    std::vector<std::string> res;
    size_t endL,startL;
    endL=0;
    startL =0;

    while(endL < str.length()){
        endL = str.find_first_of(del,startL);
        res.push_back(str.substr(startL,endL-startL));
        startL = endL+1;
    }

    return res;

}

std::vector<std::pair<size_t, size_t>> Util::splitStringSplitters(const std::string& str, const char& del)
{
    std::vector<std::pair<size_t, size_t>> res;
    size_t endL, startL;
    endL = 0;
    startL = 0;

    while (endL < str.length()) {
        endL = str.find_first_of(del, startL);
        res.push_back(std::make_pair( startL,endL - startL ));
        startL = endL + 1;
    }

    return res;
}


std::vector<std::string> Util::splitStringStream(const std::string& str, const char& del)
{
    std::stringstream strStream(str);
    std::vector<std::string> res;
    std::string tmp;
    while (std::getline(strStream, tmp, del)) {
        res.push_back(tmp);
    }

    return res;
}

unsigned long Util::dateToLong(const std::string& str)
{
    std::stringstream descrStream(str);
    char tmp;
    unsigned long year, month, day, hour, minute, second;

    descrStream >> year >> tmp >> month >> tmp >> day >> hour >> tmp >> minute >> tmp >> second;

    year -= 2000;
    return second + minute * 60ul + hour * 3600ul + day * 86400ul + month * (unsigned long)(86400ul * 30.4167) + year * 86400ul * 365ul;
}

void Util::startTimer()
{
    startTime = std::chrono::steady_clock::now();
    std::cout << "Start Clock" << std::endl;
}

long long Util::stopTimer(const std::string& functionName)
{
    auto endTime = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    std::cout<<"Execution Time for  "  << functionName<<  " : "<< duration << "[microS]" << std::endl;
    return duration;
}

