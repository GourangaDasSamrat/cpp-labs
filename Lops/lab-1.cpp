// while loop

#include <iostream>

using namespace std;

int main() {
  int Pizza;

  cout << "Enter the number of pizza you wanna serve: ";
  cin >> Pizza;

  while (Pizza > 0) {
    Pizza--;
    cout << "Serving a pizza \n" << Pizza << " remaining" << endl;
  }

  cout << "All pizzas are served";

  return 0;
}