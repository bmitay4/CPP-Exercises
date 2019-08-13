//Exmaple of using const on pointers, and the different of its location
#include <iostream>
using namespace std;

int main(){
  //declare values
  int value1 = 100;
  int value2 = 200;
  //pTwo is const, the value can changes
  int * const pTwo = &value1;
  value1++;
  cout << *pTwo << endl;
  (*pTwo)++;
  cout << *pTwo << endl;

  //pTwo = &value2; This can't be done!
  //pOne can changes, its value const
  const int * pOne = &value1;
  value1++;
  cout << *pTwo << endl;
  pOne = &value2;
  //(*pOne)++;  This can't be done!
  cout << *pTwo << endl;

  //Make no change at pOne value, remains 103
  //Because pOne is still point at value1
  value2 = 1000;
  cout << *pTwo << endl;
  //OutPut:103

  value1 = 1000;
  cout << *pTwo << endl;
  //OutPut:1000

  return 0;
}
