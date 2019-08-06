//Example of a simple class (no private members, no function and no constructors)
#include <iostream>
using namespace std;
class Cat{
public:     //Had to note its public, default is private
  int itsAge;
  int itsWeight;
};

int main(){
  Cat Frisky;
  Frisky.itsAge = 5;  //Assing to the class member a value
  cout << "Frisky's age is " << Frisky.itsAge << endl;

  return 0;
}
