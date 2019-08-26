#include "SimpleCat.hpp"

//Functions Decleration
SimpleCat f1 (SimpleCat cat);
SimpleCat* f2 (SimpleCat *cat);

SimpleCat f1 (SimpleCat cat){
  cout << "f1 called, return..\n";
  return cat;
}
SimpleCat* f2 (SimpleCat *cat){
  cout << "f2 called, return..\n";
  return cat;
}

int main(){
  cout << "Creat a Cat" << endl;
  SimpleCat Bob;
  cout << "Calling f1\n";
  f1(Bob);
  cout << "Calling f2\n";
  f2(&Bob);

  return 0;
}
