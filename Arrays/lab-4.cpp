// pointer

#include <iostream>

using namespace std;

int* prepareCoffeeOrders(int cups) {
    int* orders = new int[cups];

    for (int i = 0; i < cups; i++) {
        orders[i] = (i + 1) * 10;
    }

    return orders;
}

int main() {
    int cups = 0;

    cout << "Enter how may cups of coffee you want: ";
    cin >> cups;

    int* coffeeOrders = prepareCoffeeOrders(cups);

    for (int i; i < cups; i++) {
        cout << "Cup " << i + 1 << " has " << coffeeOrders[i] << " ml coffee" << endl;
    }

    // memory cleanup
    delete[] coffeeOrders;

    return 0;
}