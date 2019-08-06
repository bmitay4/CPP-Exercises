//Here we'll code the body of cat's class function
//Note that we should include its hpp file
#include "Cat.hpp"

Cat::Cat(){
  itsAge = 0;
}
Cat::Cat(int value){
  itsAge = value;
}
Cat::~Cat(){
}
int Cat::getAge() const{
  return itsAge;
}
void Cat::setAge(int value){
  itsAge = value;
}
void Cat::meow(){
  cout << "Meow" << endl;
}

int main(){
  Cat Frisky; //OK!, we have a constructor for it
  Cat Bill(3);//OK!, we have a constructor for it
  Frisky.meow();
  Bill.meow();
  cout << "Frisky's age is " << Frisky.getAge() << endl;
  cout << "Bill's age is " << Bill.getAge() << endl;
  Bill.setAge(90);
  Frisky.setAge(100);
  cout << "Frisky's age is " << Frisky.getAge() << endl;
  cout << "Bill's age is " << Bill.getAge() << endl;

  return 0;
}
