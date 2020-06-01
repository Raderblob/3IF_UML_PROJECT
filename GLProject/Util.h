//
// Created by richard on 23/05/2020.
//

#ifndef GLPROJECT_UTIL_H
#define GLPROJECT_UTIL_H


#include <string>
#include <vector>
#include <chrono>
class Util {
public:
    static std::vector<std::string> splitString(const std::string& str, const char& del);
    static std::vector < std::pair<size_t,size_t> > splitStringSplitters(const std::string& str, const char& del);
    static std::vector<std::string> splitStringStream(const std::string& str, const char& del);
    static unsigned long dateToLong(const std::string& str);
    static void startTimer();
    static long long stopTimer(const std::string& functionName);

};


#endif //GLPROJECT_UTIL_H
