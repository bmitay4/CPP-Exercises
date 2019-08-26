#include <iostream>
using namespace std;

int main(){
  int varOne;
  const int const *pvarOne;
  pvarOne = &varOne;
  varOne = 6;

  *pvarOne = 7;
  int varTwo;
  pvarOne = &varTwo;

  return 0;
}
