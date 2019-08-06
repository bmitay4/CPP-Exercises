//Header file, here we'll define the class and function's declarations
#include <iostream>
using namespace std;
class Cat{
  private:
     int itsAge;
public:
  Cat();
  Cat(int value);
  ~Cat();
  int getAge() const;
  /*
  By doing the following, getAge() function will become inline function
  int getAge() const {return itsAge;}
  */
  void setAge(int value);
  void meow();
};
