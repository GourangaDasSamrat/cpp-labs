// copy constructor

#include <iostream>
#include <vector>

using namespace std;

class Form {
  // access modifier
public:
  // data members / attributes /property
  string *fullName;
  int mobileMNumber;
  string emailAddress;
  vector<string> skills;

  // parameterized constructor
  Form(string name, int mobile, string mail, vector<string> skill) {
    // here both are valid
    fullName = new string(name);
    mobileMNumber = mobile;
    emailAddress = mail;
    skills = skill;
  }

  // copy constructor
  Form(const Form &other) {
    fullName = new string(*other.fullName);
    mobileMNumber = other.mobileMNumber;
    emailAddress = other.emailAddress;
    skills = other.skills;
  }

  // destructor
  ~Form() { delete fullName; }

  // member function / method
  void displayDetails() {
    cout << "Full name: " << *fullName << endl;
    cout << "Mobile number: " << mobileMNumber << endl;
    cout << "Email address: " << emailAddress << endl;
    cout << "SKills: ";

    // specialized loop for array
    for (string skill : skills) {
      cout << skill << ", ";
    }

    cout << "\n" << endl;
  }
};

int main() {
  Form userOne("Gouranga Das Samrat", 1282984834, "gouranga.samrat@gmail.com",
               {"PYthon", "JavaScript", "C++"});

  //   userOne.displayDetails();

  // copy the object
  Form copiedUser = userOne;

  //   copiedUser.displayDetails();

  *userOne.fullName = "Mr me";
  userOne.displayDetails();

  copiedUser.displayDetails();

  return 0;
}