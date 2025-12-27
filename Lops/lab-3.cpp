// for loop

#include <iostream>

using namespace std;

int main() {
  int teaCups;

  cout << "Enter the number of pizza you wanna serve: ";
  cin >> teaCups;

  for (int i = 1; i <= teaCups; i++) {
    cout << "Brewing cup " << i << " of tea..." << endl;
  }

  return 0;
}