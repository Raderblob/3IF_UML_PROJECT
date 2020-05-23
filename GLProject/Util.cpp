//
// Created by richard on 23/05/2020.
//

#include "Util.h"

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
