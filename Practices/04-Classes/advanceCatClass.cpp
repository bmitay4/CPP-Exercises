//Example of an advance class (private members, function but no constructors)
#include <iostream>
using namespace std;
class Cat{
private:
  int itsAge; //Making this variable private, make it untoucheble from the outside
public:
  int getAge();
  void setAge(int value);
  void meow();
};
//Now we'll define the functions we just set in the class, using ::
int Cat::getAge(){
  return itsAge;
}
void Cat::setAge(int value){
  itsAge = value;
}
void Cat::meow(){
  cout << "Meow!\n";
}

//In the main function we'll create a cat object, and use all the function at that object
int main(){
  Cat Frisky;
  Frisky.setAge(7);
  Frisky.meow();
  cout << "Frisky's age is " << Frisky.getAge() << endl;
  Frisky.meow();
/* The following won't work, as we define itsAge as a private member
  cout << "Frisky's age is " << Frisky.itsAge << endl;
*/

  return 0;
}
