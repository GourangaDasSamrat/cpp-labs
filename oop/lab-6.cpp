// getter and setter

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Coffee {
private:
  string coffeeName;
  int servings;
  vector<string> ingredients;

public:
  Coffee() {
    coffeeName = "Unknown coffee";
    servings = 1;
    ingredients = {"Milk", "Coffee beans", "Cream"};
  }

  Coffee(string name, int serve, vector<string> ingredients)
      : coffeeName(name), servings(serve), ingredients(ingredients) {}

  // getter for Coffee name
  string getCoffeeName() { return coffeeName; }

  // setter for Coffee name
  void setCoffeeName(string name) { coffeeName = name; }

  // getter for servings
  int getServings() { return servings; }

  // setter for servings
  void setServings(int serve) { servings = serve; }

  // getter for ingredients
  vector<string> getIngredients() { return ingredients; }

  // setter for ingredients
  void setIngredients(vector<string> item) { ingredients = item; }

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
  Coffee coffee;

  coffee.setCoffeeName("Cold brew");
  coffee.setServings(10);
  coffee.setIngredients({"Coffee beans", "Ice", "Milk"});

  coffee.displayCoffeeDetails();

  cout << coffee.getCoffeeName() << endl;
  cout << coffee.getServings() << endl;
  for (string item : coffee.getIngredients()) {
    cout << item << ", ";
  }

  return 0;
}