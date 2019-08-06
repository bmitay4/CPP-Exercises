#include <iostream>
using namespace std;

class Cat{
private:
  int itsAge;
public:
  Cat(int initAge); //constructor
  ~Cat();           //destructor
  int getAge() const;
};

//Cat's constructor define
Cat::Cat(int initAge){
  itsAge = initAge;
}
//Cat's destructor define (no action needed)
Cat::~Cat(){

}
int Cat::getAge() const{
  return itsAge;
}
int main(){
  //Some main..
  return 0;
}
