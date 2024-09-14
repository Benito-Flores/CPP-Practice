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

#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

// Your functions here

/// @brief Calculates the area of a box
/// @param width The width of the box
/// @param length The length of the box
/// @return The area of the box
int getArea(int width, int length)
{
  int area = length * width;
  return area;
}

/// @brief Calculates the volume of a box
/// @param width The width of the box
/// @param length The length of the box
/// @param height The height of the box
/// @return The volume of the box
int getVolume(int width, int length, int height)
{
  int area = getArea(width, length);
  int volume = area * height;
  return volume;
}

/// @brief Calculates the amount leftover from the box after making a cutout
/// @param cutoutSize The size of the cutout
/// @return The amount leftover from the box
int leftoverCardboard(int cutoutSize)
{
  cutoutSize = cutoutSize * cutoutSize * 4;
  return cutoutSize;
}

/// @brief Get's the maximum height possible the box can be before there's no
/// base left
/// @param width The initial width of the box
/// @param length The initial length of the box
/// @return The maximum possible height of the box
int getMaxHeight(int width, int length)
{
  int maxHeight = 0;
  int initialWidth = width;
  int initialLength = length;
  for (int i = 0; initialWidth > 0 && initialLength > 0; i++) {
    initialWidth = width;
    initialLength = length;
    initialWidth -= (i * 2);
    initialLength -= (i * 2);
    if (initialLength <= 0 || initialWidth <= 0)
      break;
    maxHeight = i;
  }
  return maxHeight;
}

/// @brief Gets the best possible height to volume ratio for the box
/// @param width The initial width of the box
/// @param length The initial length of the box
/// @return The best possible height of the box that provides the best height to
/// volume ration
int getBestHeight(int width, int length)
{
  int currentVolume = 0;
  int bestVolume = 0;
  int height = 0;
  for (int i = 1; currentVolume == bestVolume; i++) {
    width -= 2;
    length -= 2;
    currentVolume = getVolume(width, length, i);
    if (currentVolume >= bestVolume) {
      bestVolume = currentVolume;
    } else {
      break;
    }
    height++;
  }
  return height;
}

/// @brief Creates a formatted string that represents the dimensions of the box
/// along with the volume and leftover from making a coutout
/// @param w The width of the box
/// @param l The length of the box
/// @param h The height of the box
/// @return A string containing the box's dimensions and proper formatting
string createBoxStatsString(int w, int l, int h)
{
  int volume = getVolume(w, l, h);
  int leftOver = leftoverCardboard(h);
  stringstream outStream;
  outStream << left << setw(8) << h;
  outStream << left << setw(8) << w;
  outStream << left << setw(8) << l;
  outStream << left << setw(8) << volume;
  outStream << leftOver;
  return outStream.str();
}

/// @brief Prints the table with specified values along with the dimenstions
/// and specifications for the box based on the length and the width. Also
/// highlights the best height option for maximum volume with "***"
/// @param width The initial width of the box
/// @param length The initial length of the box
void printBoxOptions(int width, int length)
{
  cout << left << setw(8) << "Height" << left << setw(8) << "Width" << left
       << setw(8) << "Length" << left << setw(8) << "Volume"
       << "Leftover Amount" << endl;
  int bestHeight = getBestHeight(width, length);
  for (int i = 1; width >= 1 && length >= 1; i++) {
    width -= 2;
    length -= 2;
    string stats = createBoxStatsString(width, length, i);
    if (bestHeight == i) {
      cout << stats << "***" << endl;
    } else {
      cout << stats << endl;
    }
    if (width <= 1 || length <= 1)
      break;
  }
}

///----------------------------------------------------------------------------------
/// Tests
/// Uncomment tests to work on them. Make sure any test that does not
/// compile or causes a crash gets commented back out. Any test that runs
/// should be left on (uncommented), even if the test fails.
///----------------------------------------------------------------------------------

TEST_CASE("getArea")
{
  cout << "1: getArea" << endl;
  CHECK(getArea(2, 4) == 8);
  CHECK(getArea(12, 7) == 84);
}

TEST_CASE("getVolume")
{
  cout << "2: getVolume" << endl;
  CHECK(getVolume(2, 4, 3) == 24);
  CHECK(getVolume(12, 7, 2) == 168);
}

TEST_CASE("leftoverCardboard")
{
  cout << "3: leftoverCardboard" << endl;
  CHECK(leftoverCardboard(3) == 36);
  CHECK(leftoverCardboard(10) == 400);
}

TEST_CASE("getMaxHeight")
{
  cout << "4: getMaxHeight" << endl;
  CHECK(getMaxHeight(5, 10) == 2);
  CHECK(getMaxHeight(10, 5) == 2);
  CHECK(getMaxHeight(12, 16) == 5);
  CHECK(getMaxHeight(18, 16) == 7);
}

TEST_CASE("getBestHeight")
{
  cout << "5: getBestHeight" << endl;
  CHECK(getBestHeight(10, 15) == 2);
  CHECK(getBestHeight(15, 10) == 2);
  CHECK(getBestHeight(16, 14) == 3);
  CHECK(getBestHeight(20, 22) == 4);
  CHECK(getBestHeight(300, 180) == 36);
}

TEST_CASE("createBoxDescription")
{
  cout << "6: createBoxDescription" << endl;

  string test1 = createBoxStatsString(8, 6, 2);
  string goal1 = "2       8       6       96      16";
  // INFO will only print if test is failed
  INFO("test1|", test1, "|");
  INFO("goal1|", goal1, "|");
  CHECK(test1 == goal1);

  string test2 = createBoxStatsString(13, 20, 4);
  string goal2 = "4       13      20      1040    64";
  // INFO will only print if test is failed
  INFO("test2|", test2, "|");
  INFO("goal2|", goal2, "|");
  CHECK(test2 == goal2);
}

TEST_CASE("printBoxOptions")
{
  cout << "7: printOptions" << endl;

  // Not really an automated test. Need to verify output manually

  cout << R"(Expected:
Height  Width   Length  Volume  Leftover Amount
1       18      13      234     4
2       16      11      352     16
3       14      9       378     36***
4       12      7       336     64
5       10      5       250     100
6       8       3       144     144
7       6       1       42      196
--------------------------------------------------
)";

  cout << "Result:" << endl;
  printBoxOptions(20, 15);
}
