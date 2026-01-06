// parameterized constructor

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
  Form(string name, int mobile, string mail, vector<string> skill) {
    fullName = name;
    mobileMNumber = mobile;
    emailAddress = mail;
    skills = skill;
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
  Form userOne("Gouranga Das Samrat", 1282984834, "gouranga.samrat@gmail.com",
               {"PYthon", "JavaScript", "C++"});
  userOne.displayDetails();

  return 0;
}