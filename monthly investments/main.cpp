#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
  // print balance to two decimal places
  cout << fixed << setprecision(2);

  //  prompt user to input monthly investment, annual interest rate, and number
  //  of years
  cout << "What is your monthly investment, annual interest rate, and number "
          "of years?\n";
  double monthlyInvestment, APR, numYears;
  cin >> monthlyInvestment >> APR >> numYears;

  // convert APR to decimal APR
  double decimalAPR = APR / 100;

  // covert decimal APR to annual multiplier
  double annualMultiplierAPR = decimalAPR + 1;

  // covert annual multiplier to monthly APR
  double monthlyAPR = pow(annualMultiplierAPR, 1.0 / 12.0);

  // loop that prints year, month, and balance
  double balance = 0;
  cout << "Year#"
       << " / "
       << "Month#"
       << " / "
       << "Balance" << endl;
  for (int i = 1; i <= numYears; i++) {
    for (int j = 1; j <= 12; j++) {
      balance = balance * monthlyAPR + monthlyInvestment;
      cout << setw(2) << i << setw(5) << "/" << setw(3) << j << setw(6) << "/"
           << balance << endl;
    }
  }

  return 0;
}