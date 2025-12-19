// Arithmetic operator

#include <iostream>

using namespace std;

int main() {
  // initialize variables
  int num1;
  int num2;

  // ask user for num1 and num2
  cout << "Enter your number 1: ";
  cin >> num1;
  cout << "Enter your number 2: ";
  cin >> num2;

  // arithmetic operations
  int addition = num1 + num2;
  int substraction = num1 - num2;
  int multiplication = num1 * num2;
  int division = num1 / num2;
  int modulus = num1 % num2;

  // prints (answers)
  cout << "Addition of num1 and num2 is: " << addition << "\n";
  cout << "Substraction of num1 and num2 is: " << substraction << "\n";
  cout << "Multiplication of num1 and num2 is: " << multiplication << "\n";
  cout << "Division of num1 and num2 is: " << division << "\n";
  cout << "Modulus of num1 and num2 is: " << modulus << "\n";

  return 0;
}