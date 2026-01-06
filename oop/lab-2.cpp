// default constructor

#include <iostream>
#include <vector>

using namespace std;

class Form {
  // access modifier
public:
  // data members / attributes /property
  string fullName;
  int mobileMNumber;
  string emailAddress;
  vector<string> skills;

  // default constructor
  Form() {
    fullName = "Gouranga Das Samrat";
    mobileMNumber = 19101818;
    emailAddress = "gouranga.samrat@gmail.com";
    skills = {"C++", "PYthon", "JavaScript", "TypeScript"};
  }

  // member function / method
  void displayDetails() {
    cout << "Full name: " << fullName << endl;
    cout << "Mobile number: " << mobileMNumber << endl;
    cout << "Email address: " << emailAddress << endl;
    cout << "SKills: ";

    // specialized loop for array
    for (string skill : skills) {
      cout << skill << ", ";
    }

    cout << endl;
  }
};

int main() {
  Form userOne;
  userOne.displayDetails();

  return 0;
}