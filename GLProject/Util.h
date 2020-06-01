//
// Created by richard on 23/05/2020.
//

#ifndef GLPROJECT_UTIL_H
#define GLPROJECT_UTIL_H


#include <string>
#include <vector>
#include <chrono>
#include "Coordinate.h"
class Util {
public:
    /**
    * Splits string into a vector of strings.
    *
    * @param value contains the string .
    * @param delimiter
    * @return vector of substrings.
    */
    static std::vector<std::string> splitString(const std::string& str, const char& del);

    /**
    * Splits string into a vector of positions.
    *
    * @param value contains the string and the delimiter.
    * @param delimiter.
    * @return vector of positions in main string.
    */
    static std::vector < std::pair<size_t,size_t> > splitStringSplitters(const std::string& str, const char& del);

    /**
    * Splits string into a vector of positions.
    *
    * @param value contains the string.
    * @param delimiter.
    * @return vector of positions in main string.
    */
    static std::vector<std::string> splitStringStream(const std::string& str, const char& del);

    /**
    * Converts date format to long
    *
    * @param value contains the date in the correct format (does not check format)
    * @return date in long (0 = start of the year 2000).
    */
    static unsigned long dateToLong(const std::string& str);


    ///Starts internal Timer, Do not have multiple timers running at the same time
    static void startTimer();

    /**
    * Stops timer and returns Value, also prints result into the cout
    *
    * @param String containing function name
    * @return time in microseconds since the last startTimer()
    */
    static long long stopTimer(const std::string& functionName);

    /**
    * Calculates the distance between two Coordinates
    *
    * @param Coordinate number 1
    * @param Coordinate number 2
    * @return diastance in km between the points
    */
    static double getKm(const data::Coordinate& coord1, const data::Coordinate& coord2);

};


#endif //GLPROJECT_UTIL_H
