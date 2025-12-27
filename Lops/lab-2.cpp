// do while loop

#include <iostream>
#include <string>

using namespace std;

int main() {
  string response;

  do {
    cout << "Do you need more pizza (yes/no) ? ";
    cin >> response;
  } while (response != "no");

  return 0;
}