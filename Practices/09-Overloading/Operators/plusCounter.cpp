//Example of oveload the increment operator (++, prefix)
#include <iostream>
using namespace std;

class Counter{
public:
  Counter();
  ~Counter();
  int getValue() const;
  void setValue(int num);
  const Counter& operator++();
private:
  int itsValue;
};
Counter::Counter():
itsValue(1){
};
Counter::~Counter(){

}
const Counter& Counter::operator++(){
  ++itsValue;
  return *this;
}
int Counter::getValue() const{
  return itsValue;
}
void Counter::setValue(int num){
  itsValue = num;
}

int main(){
  //Creating a new instance of Counter class
  Counter c;
  cout << "c's value is: " << c.getValue() << endl;

  //Increment by 1. Note, we're not using the returned value
  ++c;
  cout << "c's value is: " << c.getValue() << endl;

  //Now we're using the returned value with the same operation
  Counter b = ++c;
  cout << "b's value is: " << c.getValue() << endl;

  return 0;
}
