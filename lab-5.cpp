// data type casting

#include <iostream>
using namespace std;

int main() {
  float teaPrice = 12.999;
  int roundedTeaPrice = (int)teaPrice;

  int teaQuantity = 23;
  //   int totalPrice = teaQuantity * teaPrice;
  double totalPrice = teaQuantity * teaPrice;

  cout << totalPrice << endl;
  return 0;
}
