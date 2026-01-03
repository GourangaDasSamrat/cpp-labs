#include <iostream>
#include <vector>

using namespace std;

class Form {
   public:
    // data members / attributes /property
    string fullName;
    int mobileMNumber;
    string emailAddress;
    vector<string> skills;

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

    userOne.fullName = "Gouranga Das Samrat";
    userOne.mobileMNumber = 123456789;
    userOne.emailAddress = "gouranga.samrat@gmail.com";
    userOne.skills = {"JavaScript", "TypeScript", "C++", "SQL"};

    userOne.displayDetails();

    Form userTwo{"Samrat", 123456789, "gouranga.samrat@example.com", {"C++", "SQL", "Go", "Ruby"}};

    userTwo.displayDetails();

    return 0;
}