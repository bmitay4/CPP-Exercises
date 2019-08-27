//Simple way to sum two numbers, using a function
#include <iostream>
using namespace std;

class Counter{
public:
  Counter();          //Defualt Constructor
  Counter(int value); //Initial Constructor
  ~Counter(){};       //Destructor
  int getValue() const {return itsValue;}
  void setValue(int x){itsValue = x;}
  Counter Add(const Counter &);
private:
  int itsValue;
};
Counter::Counter():
itsValue(0)
{}
Counter::Counter(int value):
itsValue(value)
{}
Counter Counter:: Add(const Counter &rhs){
  return Counter(itsValue + rhs.getValue());
}

int main(){
  Counter varOne(2), varTwo(10), varThree;
  cout << "Counter varOne value: " << varOne.getValue() << endl;
  cout << "Counter varTwo value: " << varTwo.getValue() << endl;
  cout << "Counter varThree value: " << varThree.getValue() << endl;

  //Sum the value of varOne and varTwo and insert it into varThree
  varThree = varOne.Add(varTwo);
  cout << "Counter varOne value: " << varOne.getValue() << endl;
  cout << "Counter varTwo value: " << varTwo.getValue() << endl;
  cout << "Counter varThree value: " << varThree.getValue() << endl;

  return 0;
}
