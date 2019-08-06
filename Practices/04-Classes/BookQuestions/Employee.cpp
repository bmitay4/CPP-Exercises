#include <iostream>
#include "Employee.hpp"
using namespace std;

//Define Employee constructor
Employee::Employee(int age, int yearsOfService, int salary){
  itsAge = age;
  itsYearOfService = yearsOfService;
  itsSalary = salary;
}
//Function that print all employee's specs
void Employee::getFullDetails(Employee e) const{
  cout << "age:\t" << e.getAge() << endl;
  cout << "year of service:\t" << e.getYearsOfService() << endl;
  cout << "salary:\t" << e.getSalary() << endl;
  cout << "total salay paid:\t" << e.getSalary()*e.getSalary() << endl;
  cout << "----------------\n";
}
int main(){
  Employee e1(30, 4, 2000);
  Employee e2(34, 10, 2200);
  cout << "Employee 1 Details:\n";
  e1.getFullDetails(e1);
  cout << "Employee 2 Details:\n";
  e1.getFullDetails(e2);

  return 0;
}
