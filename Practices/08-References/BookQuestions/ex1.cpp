//Using an int variable, a pointer and a reference to change its value
#include <iostream>
using namespace std;

void const printValues(int x, int *ptrx, int &rx){
  cout << "x value: " << x << endl;
  cout << "*ptrx value: " << *ptrx << endl;
  cout << "&rx value: " << rx << endl;
  cout << "\n";
}

int main(){
  int x = 100;
  int *ptrx = &x;
  int &rx = x;
  printValues(x, ptrx, rx);

  cout << "x change to 200" << endl;
  x = 200;
  printValues(x, ptrx, rx);

  cout << "*ptrx change to 500" << endl;
  *ptrx = 500;
  printValues(x, ptrx, rx);

  cout << "*rx change to 10" << endl;
  rx = 10;
  printValues(x, ptrx, rx);
  return 0;
}
