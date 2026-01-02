// lambda function

#include <iostream>

using namespace std;

int main() {
  auto servedCoffee = [](int cups) { cout << "Serving " << cups << " cups coffee" << endl; };

  servedCoffee(10);

  return 0;
}