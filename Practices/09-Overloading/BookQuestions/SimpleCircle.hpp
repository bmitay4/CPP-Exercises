#include <iostream>
using namespace std;

class SimpleCircle{
public:
  SimpleCircle();
  SimpleCircle(int);
  SimpleCircle(const SimpleCircle&);
  ~SimpleCircle();
  int getRadius() const;
  void setRadius(int);
  const SimpleCircle& operator++();    //prefix overload operator
  const SimpleCircle operator++(int);    //postfix overload operator
  const SimpleCircle operator=(const SimpleCircle&);

private:
  int *itsRadius;
};
SimpleCircle::SimpleCircle(){
  itsRadius = new int;
  *itsRadius = 5;
  //equal to itsRadius = new int(5)
}
SimpleCircle::SimpleCircle(int x){
  itsRadius = new int;
  *itsRadius = x;
}
SimpleCircle::~SimpleCircle(){
  cout << "Destructor Called" << endl;
  cout << "Delete itsRadius variable" << endl;
  delete itsRadius;
  itsRadius = 0;
}
int SimpleCircle::getRadius() const{
  return *itsRadius;
}
SimpleCircle::SimpleCircle(const SimpleCircle &rhs){
  itsRadius = new int(rhs.getRadius());
}

void SimpleCircle::setRadius(int x){
  *itsRadius = x;
}
const SimpleCircle& SimpleCircle::operator++(){
  ++(*itsRadius);
  return *this;
}
const SimpleCircle SimpleCircle::operator++(int x){
  SimpleCircle temp(*this);
  ++(*itsRadius);
  return temp;
}
const SimpleCircle SimpleCircle::operator=(const SimpleCircle &rhs){
  if(this != &rhs){
    cout << "The instances are not the same!\n";
    *itsRadius = rhs.getRadius();
  }
  else cout << "The instances are the same!\nNo action taken\n";
  return *this;
}
