#include <iostream>
using namespace std;

class SimpleCat{
public:
  SimpleCat();            //Default Constructor
  SimpleCat(SimpleCat&);  //Copy Constructor
  ~SimpleCat();           //Destructor
private:
  int itsAge;
  int itsWeight;
};

SimpleCat::SimpleCat(){
  cout << "..Default Constructor Called" << endl;
}
SimpleCat::SimpleCat(SimpleCat&){
  cout << "..Copy Constructor Called" << endl;
}
SimpleCat::~SimpleCat(){
  cout << "..Destructor Called" << endl;
}
