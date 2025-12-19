// Relational operators using variables
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

  // relational operations stored in boolean variables
  bool is_equal = (num1 == num2);
  bool is_not_equal = (num1 != num2);
  bool is_greater = (num1 > num2);
  bool is_less = (num1 < num2);
  bool is_greater_equal = (num1 >= num2);
  bool is_less_equal = (num1 <= num2);

  // prints (answers)
  // We use boolalpha so it prints "true/false" instead of "1/0"
  cout << boolalpha;

  cout << "num1 == num2 is: " << is_equal << "\n";
  cout << "num1 != num2 is: " << is_not_equal << "\n";
  cout << "num1 > num2 is: " << is_greater << "\n";
  cout << "num1 < num2 is: " << is_less << "\n";
  cout << "num1 >= num2 is: " << is_greater_equal << "\n";
  cout << "num1 <= num2 is: " << is_less_equal << "\n";

  return 0;
}