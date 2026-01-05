// pointer

#include <iostream>

using namespace std;

int main() {
  string foodsTypes[3][4] = {
      {
          "Cold Brew",
          "Cappuccino",
          "Mocha",
          "Iced Coffees",
      },
      {
          "Neapolitan",
          "Chicago Deep-Dish",
          "Sicilian",
          "Detroit-Style",
      },
      {"Kashmiri", "Ginger", "Milk", "Traditional"},
  };

  for (int i = 0; i < 3; i++) {
    cout << "Food " << i + 1 << " ->" << endl;
    for (int j = 0; j < 4; j++) {
      cout << "Food type : " << foodsTypes[i][j] << endl;
    }
  }

  return 0;
}
