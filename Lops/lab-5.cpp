// continue in loop

#include <iostream>
#include <string>

using namespace std;

int main() {
  string pizzaTypes[4] = {"Calzone", "Neapolitan", "Chicago Deep-Dish",
                          "Sicilian"};

  for (int i = 0; i < 4; i++) {
    if (pizzaTypes[i] == "Neapolitan") {
      cout << "Skipping " << pizzaTypes[i] << endl;
      continue;
    }

    cout << "Making " << pizzaTypes[i] << "..." << endl;
  }

  return 0;
}