#include "Cat.hpp"

int main(){
  Cat Bob;
  cout << "Bob's age is: " << Bob.getAge() << endl;

  //set bob's age to 6
  Bob.setAge(6);

  //Creat a DEEP COPY of Bob
  Cat Alice(Bob);

  cout << "Bob's age is: " << Bob.getAge() << endl;
  cout << "Alice's age is: " << Alice.getAge() << endl;

  //reset bob's age to 10
  Bob.setAge(10);

  cout << "Bob's age is: " << Bob.getAge() << endl;
  cout << "Alice's age is: " << Alice.getAge() << endl;

  return 0;
}
