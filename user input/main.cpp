#include <iostream>
#include <string>

using namespace std;

int main() {
  string userName;
  int userID;

  cout << "What is your legal fullname?\n";
  getline(cin, userName);

  cout << "What is you " << userName << " account's user id?\n";
  cin >> userID;

  cout << "Your username is " << userName << " and your userid is " << userID
       << endl;
  return 0;
}