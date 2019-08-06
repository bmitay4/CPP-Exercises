//Example of a class (private members, function and constructors/destructors)
#include <iostream>
using namespace std;

class Cat{
private:
  int itsAge;
public:
  Cat();            //default constructor
  Cat(int initAge); //init constructor
  ~Cat();           //destructor
  int getAge() const; //The const word make sure that this functions can't change class's members
};

//Cat's init constructor define
Cat::Cat(int initAge){
  itsAge = initAge;
}
//Cat's default constructor define
Cat::Cat(){
  itsAge = 0;
}
//Cat's destructor define (no action needed)
Cat::~Cat(){

}
int Cat::getAge() const{
  return itsAge;
}
int main(){
  //Some code..
  return 0;
}
