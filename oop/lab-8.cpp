// encapsulations

#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
  string accountNumber;
  double balance;

public:
  BankAccount(string accNum, double initialBalance)
      : accountNumber(accNum), balance(initialBalance) {}

  // check balance
  double getBalance() const { return balance; }

  // deposit money
  void deposit(double amount) {
    if (amount > 0) {
      balance += amount;
      cout << "Deposited: $" << amount << endl;
    } else {
      cout << "Invalid deposit amount!" << endl;
    }
  }

  // withdraw money
  void withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
      balance -= amount;
      cout << "Withdrawn: $" << amount << endl;
    } else {
      cout << "Invalid withdraw amount!" << endl;
    }
  }
};

int main() {
  BankAccount userOne("101929Ab", 100);

  int choice;
  double amount;

  do {
    cout << "\n--- Bank Menu ---\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Current Balance: $" << userOne.getBalance() << endl;
      break;

    case 2:
      cout << "Enter deposit amount: ";
      cin >> amount;
      userOne.deposit(amount);
      break;

    case 3:
      cout << "Enter withdraw amount: ";
      cin >> amount;
      userOne.withdraw(amount);
      break;

    case 4:
      cout << "Thank you for using the bank system!" << endl;
      break;

    default:
      cout << "Invalid choice! Please try again." << endl;
    }

  } while (choice != 4);

  return 0;
}
