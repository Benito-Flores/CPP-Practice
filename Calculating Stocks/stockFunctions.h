//----------------------------------------------------------
// CS161 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

#ifndef STOCK_FUNCTIONS_H
#define STOCK_FUNCTIONS_H

#include <iostream>

/**
 * @brief Calculates and returns the highest value of the stock
 *  in the range that starts at startDay and ends at endDay.
 * @param values array of stock values
 * @param startDay First day - inclusive
 * @param endDay Last day - inclusive
 * @return Highest value found
 *
 * The start and end are both inclusive - the highest value might be one
 * of them.
 *
 * Given this array: 12.25, 12.15, 12.17, 12.20, 12.06
 *
 * The highestValue from 1 through 3 is 12.20
 */
double highestValue(const double values[], int startDay, int endDay);

/**
 * @brief Find the average value within a range of days
 * @param values array of stock values
 * @param startDay First day - inclusive
 * @param endDay Last day - inclusive
 * @return mean of values
 *
 * Given this array: 12.25, 12.15, 12.17, 12.20, 12.06
 *
 * The average from 1 through 3 is ~12.17333333333333333
 */
double average(const double values[], int startDay, int endDay);

/**
 * @brief Find the standard deviation for the values within a range of days
 * @param values array of stock values
 * @param startDay First day - inclusive
 * @param endDay Last day - inclusive
 * @return standard deviation of values
 *
 * Given this array: 12.25, 12.15, 12.17, 12.20, 12.06
 *
 * The stddev from 1 through 3 is ~0.0205480466766
 *
 * How to calculate standard deviation - this is a "population" standard
 * deviation. 1) Calculate the average of the items. 2) For each item, subtract
 * the average value, then square this difference. Sum up these values. 3)
 * Divide by the number of items. 4) Take the square root.
 *
 * https://www.khanacademy.org/math/statistics-probability/summarizing-quantitative-data/variance-standard-deviation-sample/a/population-and-sample-standard-deviation-review
 */
double standardDev(const double values[], int startDay, int endDay);

/**
 * @brief Read arrSize pieces of data from the **inputSource** into the array
 * @param inputSource stream to read data from
 * @param values array of stock values
 * @param arrSize number of elements in values
 *
 * Fills the values array by reading arrSize number of doubles from the
 * inputSource. The inputSource could be a file, or a stringstream, or cin.
 *
 * Hint: just read from inputSource like it was a file or cin using >> but make
 * sure to refer to it as inputSource, not "cin".
 */
void getData(std::istream& inputSource, double values[], int arrSize);

/**
 * @brief Calculate the amount each element in values changed from the previous
 *        value and store to the changes array. The change for the first element
 *        will always be considered to be 0.
 * @param values array of stock values
 * @param changes array where results are stored
 * @param arrSize number of elements in values
 *
 * Given this array with size 5: 12.25, 12.15, 12.17, 12.20, 12.06
 * changes should be set to:     0      -0.1   0.02   0.03   -0.14
 */
void calculateChangeArray(const double values[], double changes[], int size);

/**
 * @brief Calculates the worst drop in value that might be
 *        experienced by an investor during the indicated time period.
 * @param values array of stock values
 * @param startDay First day - inclusive
 * @param endDay Last day - inclusive
 * @return The worst possible loss, expressed in $s. If the price never
 *          declines, returns 0.
 *
 * This function determines the worst possible investment situation within
 * a given time period. i.e. How much money you could possibly lose if you
 * bought at some point at or after startDay and then sold before or on endDay.
 *
 * Given this array with size 7: 10.0, 6.0, 20.0, 18.0, 13.0, 11.0, 17.0
 * The maxDrawDown from 0 to 6 is -9.0 (Buy on day 2, sell on day 5)
 * The maxDrawDown from 0 to 3 is -4.0 (Buy on day 0, sell on day 1)
 * The maxDrawDown from 3 to 5 is -7.0 (Buy on day 3, sell on day 5)
 * The maxDrawDown from 1 to 2 is 0 (No decline)
 */
double maxDrawdown(const double values[], int startDay, int endDay);

#endif // STOCK_FUNCTIONS_H
