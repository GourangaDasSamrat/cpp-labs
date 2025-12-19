// Logical operator

#include <iostream>

using namespace std;

int main() {
  bool isStudent;
  int books;

  cout << "Are you a student? (1 for yes and 0 for no): ";
  cin >> isStudent;
  cout << "How may books do you have? ";
  cin >> books;

  if (isStudent || books > 20) {
    cout << "Your are a good student";
  } else {
    cout << "Your are not a good student";
  }

  return 0;
}
