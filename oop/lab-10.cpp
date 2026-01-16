// Inheritance and final keyword

#include <iostream>
#include <memory>
#include <string>

using namespace std;

// base/parent/main class

class Coffee {
protected:
  string coffeeName;
  int servings;

public:
  Coffee(string name, int serve) : coffeeName(name), servings(serve) {
    cout << "Coffee constructor called for " << name << endl;
  }

  virtual void brew() const { cout << "Brewing " << coffeeName << endl; }
  virtual void serve() const {
    cout << "Serving " << servings << "cups of coffee" << endl;
  }

  virtual ~Coffee() {
    cout << "Coffee destructor called for " << coffeeName << endl;
  }
};

// derived classes

class ColdCoffee : public Coffee {
public:
  ColdCoffee(int serve) : Coffee("Cold coffee", serve) {
    cout << coffeeName << " constructor called" << endl;
  }

  void brew() const override {
    cout << "Brewing " << coffeeName << " with extra milk" << endl;
  }
  void serve() const override {
    cout << "Serving " << servings << "cups of coffee" << endl;
  }

  ~ColdCoffee() { cout << coffeeName << " destructor called" << endl; }
};

class Mocha : public Coffee {
public:
  Mocha(int serve) : Coffee("Mocha", serve) {
    cout << coffeeName << " constructor called" << endl;
  }

  void brew() const override final {
    cout << "Brewing " << coffeeName << " with extra chocolate" << endl;
  }

  ~Mocha() { cout << coffeeName << " destructor called" << endl; }
};

// class Latte : public Mocha {
// public:
//   void brew() const override {
//     cout << "Brewing " << coffeeName << " with extra chocolate" << endl;
//   }
// };

int main() {
  Coffee *coffee1 = new ColdCoffee(2);
  unique_ptr<Coffee> coffee2 = make_unique<Mocha>(4);

  coffee1->serve();
  coffee1->brew();

  coffee2->serve();
  coffee2->brew();

  delete coffee1;

  return 0;
}