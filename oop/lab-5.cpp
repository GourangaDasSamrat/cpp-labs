// friend keyword

#include <iostream>
#include <vector>

using namespace std;

class Coffee {
 private:
  string coffeeName;
  int servings;

 public:
  Coffee(string name, int serve) : coffeeName(name), servings(serve) {}

  friend bool compareServings(const Coffee& coffee1, const Coffee& coffee2);

  void display() const {
    cout << "Coffee name: " << coffeeName << endl;
    cout << "Servings: " << servings << "\n" << endl;
  }
};

bool compareServings(const Coffee& coffee1, const Coffee& coffee2) {
  return coffee1.servings > coffee2.servings;
}

int main() {
  Coffee cappuccino("Cappuccino", 10);
  Coffee coldBrew("Cold Brew", 6);

  cappuccino.display();
  coldBrew.display();

  if (compareServings(cappuccino, coldBrew)) {
    cout << "Cappuccino is having more servings" << endl;
  } else {
    cout << "Cappuccino is having less servings" << endl;
  }
  return 0;
}