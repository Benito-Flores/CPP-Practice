#include "postNetFunctions.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
  // read in from file
  ifstream inFile;
  inFile.open("input.txt");

  // output file
  ofstream outFile("output.txt");

  // check if file could open
  if (inFile.fail()) {
    cout << "Could not open file" << endl;
  }

  // read in lines from file
  while (!inFile.eof()) {
    string stringVar;
    getline(inFile, stringVar);
    if (inFile.fail())
      break;

    // print city, st, zip, and postnet
    outFile << getCity(stringVar) << ", " << getState(stringVar) << " "
            << getZipCode(stringVar) << "\n"
            << getPostNetCode(stringVar) << endl;
  }

  // Close file
  inFile.close();
  outFile.close();

  return 0;
}