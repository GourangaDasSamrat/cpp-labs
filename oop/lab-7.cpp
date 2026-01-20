// Delegating constructor

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Coffee {
 public:
  string coffeeName;
  int servings;
  vector<string> ingredients;

  // Delegating constructor
  Coffee(string name) : Coffee(name, 1, {"Milk", "Coffee beans", "Ice"}) {}

  Coffee(string name, int serve, vector<string> ingredients)
      : coffeeName(name), servings(serve), ingredients(ingredients) {}

  void setIngredients(vector<string> item) {
    ingredients = item;
  }

  void displayCoffeeDetails() {
    cout << "Coffee name: " << coffeeName << endl;
    cout << "Servings: " << servings << endl;
    cout << "Ingredients: ";

    for (string item : ingredients) {
      cout << item << ", ";
    }

    cout << "\n" << endl;
  }
};

int main() {
  Coffee quickCoffee("Quick Coffee");
  quickCoffee.displayCoffeeDetails();

  return 0;
}