//----------------------------------------------------------
// CS161 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

// Bring in unit testing code and tell it to build a main function
// If you have multiple unit test files, only one should have this define
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

// Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

//-----------------------------------------------------------------------------------

#include <iostream>
#include <sstream>
using namespace std;

#include "stockFunctions.h"

///----------------------------------------------------------------------------------
/// Tests
///----------------------------------------------------------------------------------

const int TEST_ARR1_SIZE = 5;
const double TEST_ARR1[TEST_ARR1_SIZE] = {12.25, 12.15, 12.17, 12.20, 12.06};

TEST_CASE("highestValue")
{
  cout << "1: highestValue" << endl;
  CHECK(highestValue(TEST_ARR1, 1, 3) == Approx(12.20));
}

TEST_CASE("average")
{
  cout << "2: average" << endl;
  CHECK(average(TEST_ARR1, 1, 3) == Approx(12.173333));
}

TEST_CASE("standardDev")
{
  cout << "3: standardDev" << endl;
  CHECK(standardDev(TEST_ARR1, 1, 3) == Approx(0.0205480));
}

TEST_CASE("getData")
{
  cout << "4: getData" << endl;

  const int TEST_ARR2_SIZE = 4;
  double TEST_ARR2[TEST_ARR2_SIZE];

  stringstream input("1.1 12.3 4.6 -1.0");
  getData(input, TEST_ARR2, TEST_ARR2_SIZE);
  CHECK(TEST_ARR2[0] == Approx(1.1));
  CHECK(TEST_ARR2[1] == Approx(12.3));
  CHECK(TEST_ARR2[3] == Approx(-1.0));
}

TEST_CASE("calculateChangeArray")
{
  cout << "5: calculateChangeArray" << endl;

  // Initialize the changes with obviously bad values
  double changes[TEST_ARR1_SIZE] = {-99, -99, -99, -99, -99};

  calculateChangeArray(TEST_ARR1, changes, TEST_ARR1_SIZE);

  CHECK(changes[1] == Approx(-0.1));
}

TEST_CASE("maxDrawdown")
{
  cout << "6: maxDrawdown" << endl;
  const int TEST_ARR2_SIZE = 7;
  const double TEST_ARR2[TEST_ARR2_SIZE] = {10.0, 6.0,  20.0, 18.0,
                                            13.0, 11.0, 17.0};
  CHECK(maxDrawdown(TEST_ARR2, 0, 6) == Approx(-9));
  CHECK(maxDrawdown(TEST_ARR2, 0, 3) == Approx(-4));
  CHECK(maxDrawdown(TEST_ARR2, 3, 5) == Approx(-7));
  CHECK(maxDrawdown(TEST_ARR2, 1, 2) == Approx(0));
}