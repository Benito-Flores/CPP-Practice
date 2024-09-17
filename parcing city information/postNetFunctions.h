#ifndef POST_NET_FUNCTIONS_H
#define POST_NET_FUNCTIONS_H

#include "postNetFunctions.h"
#include <string>
using namespace std;

/// @brief Gets the city from string
/// @param stringVar
/// @return City name
string getCity(string stringVar);

/// @brief Gets state abbreviation from string
/// @param stringVar
/// @return Two letter state abbreviation
string getState(string stringVar);

/// @brief Gets the zip code from string
/// @param stringVar
/// @return Zip code
string getZipCode(string stringVar);

/// @brief Gets checksum digit for from zip code
/// @param stringVar
/// @return checksum Code
string getCheckSumDigit(string stringVar);

/// @brief Gets the postNetCodes from zip code and checksum
/// @param stringVar
/// @return PostNet Binary String
string getPostNetCode(string stringVar);

#endif