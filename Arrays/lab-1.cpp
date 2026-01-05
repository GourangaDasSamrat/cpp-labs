// array

#include <iostream>

using namespace std;

int main() {
    string coffeeTypes[5] = {"Cold Brew", "Cappuccino", "Mocha", "Iced Coffees", "Lattes"};

    cout << "Coffee types: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << coffeeTypes[i] << endl;
    }

    return 0;
}