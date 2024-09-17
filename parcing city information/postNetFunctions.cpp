#include "postNetFunctions.h"
#include <iostream>
using namespace std;

string getCity(string stringVar)
{
  string::size_type firstComma = stringVar.find(",");
  stringVar.erase(firstComma);
  return stringVar;
}

string getState(string stringVar)
{
  string::size_type firstComma = stringVar.find(",");
  stringVar.erase(0, firstComma + 1);
  string::size_type secondComma = stringVar.find(",");
  stringVar.erase(secondComma);
  return stringVar;
}

string getZipCode(string stringVar)
{
  string::size_type firstComma = stringVar.find(",");
  stringVar.erase(0, firstComma + 1);
  string::size_type secondComma = stringVar.find(",");
  stringVar.erase(0, secondComma + 1);
  return stringVar;
}

string getCheckSumDigit(string stringVar)
{
  string zipCode = getZipCode(stringVar);
  int num = 0;
  int total = 0;
  for (string::size_type i = 0; i < zipCode.length(); i++) {
    if (zipCode[i] >= 48 && zipCode[i] <= 57) {
      num = zipCode[i] - '0';
      total = total + num;
    }
  }
  int remainder;
  int checksum;
  if (total % 10 != 0) {
    remainder = total % 10;
    checksum = 10 - remainder;
  }
  stringVar = to_string(checksum);
  return stringVar;
}

string getPostNetCode(string stringVar)
{
  string zipCode = getZipCode(stringVar) + getCheckSumDigit(stringVar);
  string binaryString = "1";
  for (string::size_type i = 0; i < zipCode.length(); i++) {
    if (zipCode[i] >= 48 && zipCode[i] <= 57) {
      if (zipCode[i] == 48) {
        binaryString += "11000";
      } else if (zipCode[i] == 49) {
        binaryString += "00011";
      } else if (zipCode[i] == 50) {
        binaryString += "00101";
      } else if (zipCode[i] == 51) {
        binaryString += "00110";
      } else if (zipCode[i] == 52) {
        binaryString += "01001";
      } else if (zipCode[i] == 53) {
        binaryString += "01010";
      } else if (zipCode[i] == 54) {
        binaryString += "01100";
      } else if (zipCode[i] == 55) {
        binaryString += "10001";
      } else if (zipCode[i] == 56) {
        binaryString += "10010";
      } else if (zipCode[i] == 57) {
        binaryString += "10100";
      }
    }
  }
  return binaryString += "1";
}
