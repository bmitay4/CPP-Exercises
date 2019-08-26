#include <iostream>
using namespace std;
class Cat{
public:
  Cat();            //Default constructor
  Cat(const Cat &); //Copy constructor
  ~Cat();           //Destructor
  int getAge() const;
  void setAge(int value);
private:
  int *itsAge;
  int *itsWeight;
};

Cat::Cat(){
  itsAge = new int;
  itsWeight = new int;
  *itsAge = 1;
  *itsWeight = 100;
}
Cat::Cat(const Cat &rhs){
  itsAge = new int;
  itsWeight = new int;
  *itsAge = rhs.getAge();      //public access
  *itsWeight = *(rhs.itsWeight); //private access
}
Cat::~Cat(){
  delete itsAge;
  delete itsWeight;
  itsAge = 0;
  itsWeight = 0;
}
int Cat::getAge() const{
  return *itsAge;
}
void Cat::setAge(int value){
  *itsAge = value;
}
