#include "stockFunctions.h"
#include <cmath>
#include <iostream>
using namespace std;

double highestValue(const double values[], int startDay, int endDay)
{
  double highestValue = 0;
  for (int i = startDay; i <= endDay; i++) {
    if (highestValue < values[i]) {
      highestValue = values[i];
    }
  }
  return highestValue;
}

double average(const double values[], int startDay, int endDay)
{
  double average = 0;
  double total = 0;
  double count = 0;
  for (int i = startDay; i <= endDay; i++) {
    total += values[i];
    count++;
  }
  average = total / count;
  return average;
}

double standardDev(const double values[], int startDay, int endDay)
{
  double averageNum = average(values, startDay, endDay);
  double eachItem = 0;
  double sumOfEach = 0;
  double count = 0;
  double total = 0;
  for (int i = startDay; i <= endDay; i++) {
    eachItem = pow((values[i] - averageNum), 2);
    sumOfEach += eachItem;
    count++;
  }
  total = sqrt(sumOfEach / count);
  return total;
}

void getData(std::istream& inputSource, double values[], int arrSize)
{
  for (int i = 0; i < arrSize; i++) {
    inputSource >> values[i];
  }
}

void calculateChangeArray(const double values[], double changes[], int size)
{
  double amountChange = 0;
  changes[0] = amountChange;
  for (int i = 1; i < size; i++) {
    amountChange = values[i] - values[i - 1];
    changes[i] = amountChange;
  }
}

double maxDrawdown(const double values[], int startDay, int endDay)
{
  double drawDown = 0;
  double maxDrawDown = 0;
  int i = startDay;
  int j = startDay;
  while (i < endDay) {
    drawDown = 0;
    while (values[j + 1] < values[j] && j < endDay) {
      drawDown += values[j + 1] - values[j];
      j++;
    }
    j++;
    i = j;
    if (drawDown < maxDrawDown) {
      maxDrawDown = drawDown;
    }
  }
  return maxDrawDown;
}