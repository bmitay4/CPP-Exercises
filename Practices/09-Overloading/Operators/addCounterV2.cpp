//Simple way to sum two numbers, using an operator +
#include <iostream>
using namespace std;

class Counter{
public:
  Counter();
  Counter(int);
  Counter(const Counter &);
  ~Counter();
  int getValue() const;
  void setValue(int);
  Counter operator + (const Counter &);
private:
  int itsValue;
};
Counter::Counter(){
  itsValue = 0;
}
Counter::Counter(int x){
  itsValue = x;
}
Counter::Counter(const Counter & rhs){
  itsValue = rhs.getValue();
}
Counter::~Counter(){
  cout << "Destructor called" << endl;
}
int Counter::getValue() const{
  return itsValue;
}
void Counter::setValue(int x){
  itsValue = x;
}
Counter Counter::operator+(const Counter &rhs){
  return Counter(itsValue+rhs.getValue());
}
int main(){
  Counter varOne(2), varTwo(4), varThree;
  cout << "Counter varOne value: " << varOne.getValue() << endl;
  cout << "Counter varTwo value: " << varTwo.getValue() << endl;
  cout << "Counter varThree value: " << varThree.getValue() << endl;

  //Sum the value of varOne and varTwo and insert it into varThree
  varThree = varOne + varTwo;
  cout << "Counter varOne value: " << varOne.getValue() << endl;
  cout << "Counter varTwo value: " << varTwo.getValue() << endl;
  cout << "Counter varThree value: " << varThree.getValue() << endl;

  //This can be done thanks to Initial Constructor we've created
  Counter varFour = 5;
  cout << "Counter varFour value: " << varFour.getValue() << endl;

  return 0;
}
