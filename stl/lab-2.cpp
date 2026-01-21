#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

struct Employee {
  int id;
  string name;
  double salary;
};

void displayEmployee(const Employee& emp) {
  cout << "ID: " << emp.id << "\n"
       << "Name: " << emp.name << "\n"
       << "Salary: $" << emp.salary << "\n"
       << endl;
};

int main() {
  vector<Employee> employees = {
    {101, "Ada Lovelace", 10000},
    {102, "Charles Darwin", 20000},
    {103, "Dmitri Mendeleev", 40000},
    {104, "Isaac Newton", 30000},
    {105, "Galileo Galilei", 50000},
  };

  sort(
    employees.begin(),
    employees.end(),
    [](const Employee& e1, const Employee& e2) {
      return e1.salary > e2.salary;
    });

  cout << "Employee sorted by their salary -> highest to lowest: \n" << endl;

  for_each(employees.begin(), employees.end(), displayEmployee);

  vector<Employee> highEarners;

  copy_if(
    employees.begin(),
    employees.end(),
    back_inserter(highEarners),
    [](const Employee& e) { return e.salary > 30000; });

  cout << "Employees who has salary more than 30000: \n" << endl;

  for_each(highEarners.begin(), highEarners.end(), displayEmployee);

  double totalSalary = accumulate(
    employees.begin(), employees.end(), 0, [](double sum, const Employee& e) {
      return sum + e.salary;
    });

  double avarageSalary = totalSalary / employees.size();

  auto highestPaid = max_element(
    employees.begin(),
    employees.end(),
    [](const Employee& e1, const Employee& e2) {
      return e1.salary < e2.salary;
    });

  return 0;
}