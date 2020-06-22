/**
 *
 *  @file OutputFormatter.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 21.06.2021
 */

#include <string>
#include <sstream>
#include "OutputFormatter.h"

std::string center(const std::string& str, int width) {
    std::stringstream centeredString;
    std::stringstream spaces;
    int padding = width - str.size();
    for(int i=0; i<padding/2; ++i)
        spaces << " ";
    centeredString << spaces.str() << str << spaces.str();
    if(padding>0 && padding%2!=0)
        centeredString << " ";
    return centeredString.str();
}
