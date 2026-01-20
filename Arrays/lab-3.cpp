// pass array inside function

#include <iostream>

using namespace std;

int totalCoffeeServed(int coffee[], int size) {
  int total = 0;
  for (int i = 0; i < size; i++) {
    total += coffee[i];
  }

  return total;
}

int main() {
  int coffeeServed[7] = {20, 54, 13, 10, 21, 39, 92};

  int total = totalCoffeeServed(coffeeServed, 7);

  cout << total << endl;
  return 0;
}