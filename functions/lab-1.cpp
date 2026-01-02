// functions

#include <iostream>

using namespace std;

// declaration & definition of function
int CheckTemp(int temp) { return temp; }

// declaration of function
void serveCoffee(int cups);

// function overloading
void serveCoffee(string type = "Cold brew", int cups = 1) {  // Cold brew and 1 is default value
  int a = 10;                                                // a is formal parameter
  cout << "Serving " << cups << " of " << type << endl;
}

int main() {
  int temp = CheckTemp(10);
  cout << temp;

  // invocation of function
  serveCoffee(40);  // 40 is actual parameter

  serveCoffee("Latte", 29);
  return 0;
}

// definition of function
void serveCoffee(int cups) { cout << "\nServred " << cups << " cups coffee" << endl; };
