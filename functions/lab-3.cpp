// pass by reference

#include <iostream>

using namespace std;

void serveCoffee(int& cups) {
  cups += 5;
  cout << "Serving " << cups << " cups coffee with " << endl;
}

int main() {
  int cups = 10;
  serveCoffee(cups);

  cout << "Value of cups: " << cups << endl;
  return 0;
}
