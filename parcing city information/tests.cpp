#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "postNetFunctions.h"

using doctest::Approx;

TEST_CASE("get city")
{
  CHECK(getCity("New York,NY,56458") == "New York");
  CHECK(getCity("Portland,OR,97201") == "Portland");
  CHECK(getCity("Oklahoma City,OK,73124-2412") == "Oklahoma City");
}

TEST_CASE("get state")
{
  CHECK(getState("New York,NY,56458") == "NY");
  CHECK(getState("Portland,OR,97201") == "OR");
  CHECK(getState("Oklahoma City,OK,73124-2412") == "OK");
}

TEST_CASE("get zip")
{
  CHECK(getZipCode("New York,NY,56458") == "56458");
  CHECK(getZipCode("Portland,OR,97201") == "97201");
  CHECK(getZipCode("Oklahoma City,OK,73124-2412") == "73124-2412");
}

TEST_CASE("get checksum")
{
  CHECK(getCheckSumDigit("New York,NY,56458") == "2");
  CHECK(getCheckSumDigit("Portland,OR,97201") == "1");
  CHECK(getCheckSumDigit("Oklahoma City,OK,73124-2412") == "4");
}

TEST_CASE("get postNet")
{
  CHECK(getPostNetCode("New York,NY,56458")
        == "10101001100010010101010010001011");
  CHECK(getPostNetCode("Bailey,CO,80421")
        == "11001011000010010010100011010101");
}