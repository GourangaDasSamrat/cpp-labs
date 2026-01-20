// access element of array

#include <iostream>

using namespace std;

int main() {
  string coffeeTypes[5] = {
    "Cold Brew", "Cappuccino", "Mocha", "Iced Coffees", "Lattes"};

  cout << "Coffee one: " << coffeeTypes[0] << endl;
  cout << "Coffee two: " << coffeeTypes[1] << endl;

  return 0;
}