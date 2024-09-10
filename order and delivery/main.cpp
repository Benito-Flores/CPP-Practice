#include <iostream>
using namespace std;

int main()
{
  // prompt user for cost of order
  cout << "What is the total cost?\n";
  double orderCost;
  cin >> orderCost;

  // prompt user for delivery type
  cout << "What kind of delivery would you like? 1 = Drone, 2 = 2-Day, 3 = "
          "Standard\n";
  int deliveryType;
  cin >> deliveryType;

  // calculate shipping charge
  double shippingCharge;

  if (deliveryType == 1 || deliveryType == 2 || deliveryType == 3) {
    if (deliveryType == 1) { // shipping charge for drone delivery
      if (orderCost <= 0) {
        cout << "Bad Input\n";
      } else if (orderCost < 100) {
        cout << "Not available\n";
      } else if (orderCost < 500) {
        shippingCharge = 50;
        cout << "Your total cost is: $" << (orderCost + shippingCharge) << endl;
      } else {
        shippingCharge = orderCost * .10;
        cout << "Your total cost is: $" << (orderCost + shippingCharge) << endl;
      }
    } else if (deliveryType == 2) { // shipping charge for 2-day delivery
      if (orderCost <= 0) {
        cout << "Bad Input\n";
      } else if (orderCost <= 300) {
        shippingCharge = 10 + orderCost * .02;
        cout << "Your total cost is: $" << (orderCost + shippingCharge) << endl;
      } else {
        cout << "FREE SHIPPING!\n"
             << "Your total cost is: $" << orderCost << endl;
      }
    } else if (deliveryType == 3) { // shipping charge for standard
      if (orderCost <= 0) {
        cout << "Bad Input\n";
      } else if (orderCost < 35) {
        shippingCharge = 5;
        cout << "Your total cost is: $" << (orderCost + shippingCharge) << endl;
      } else if (orderCost < 100) {
        shippingCharge = 8;
        cout << "Your total cost is: $" << (orderCost + shippingCharge) << endl;
      } else {
        cout << "FREE SHIPPING!\n"
             << "Your total cost is: $" << orderCost << endl;
      }
    }
  } else {
    cout << "Bad Input\n";
  }

  return 0;
}