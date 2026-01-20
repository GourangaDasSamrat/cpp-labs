// break in loop

#include <iostream>
#include <string>

using namespace std;

int main() {
  string response;

  while (true) {
    cout << "Do you need more pizza (type stop to exit) ?";
    cin >> response;

    if (response == "stop") {
      break;
    }

    cout << "Here is your another of pizza";
  }

  cout << "No more pizza will be served";

  return 0;
}