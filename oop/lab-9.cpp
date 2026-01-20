// Abstract class, virtual function and derived class

#include <iostream>

using namespace std;

// Abstract class

class Coffee {
 public:
  // virtual functions
  virtual void prepareIngredients() = 0;
  virtual void brew() = 0;
  virtual void serve() = 0;

  void makeCoffee() {
    prepareIngredients();
    brew();
    serve();
  }
};

// Derived classes

class ColdCoffee : public Coffee {
 public:
  void prepareIngredients() override {
    cout << "Coffee beans, milk and ice is ready." << endl;
  }
  void brew() override {
    cout << "Cold Coffee brewed." << endl;
  }
  void serve() override {
    cout << "Cold Coffee served.\n" << endl;
  }
};

class Mocha : public Coffee {
 public:
  void prepareIngredients() override {
    cout << "Coffee beans, espresso, steamed milk, and chocolate  is ready."
         << endl;
  }
  void brew() override {
    cout << "Mocha brewed." << endl;
  }
  void serve() override {
    cout << "Mocha served.\n" << endl;
  }
};

int main() {
  ColdCoffee coldCoffee;
  Mocha mocha;

  coldCoffee.makeCoffee();
  mocha.makeCoffee();
  return 0;
}