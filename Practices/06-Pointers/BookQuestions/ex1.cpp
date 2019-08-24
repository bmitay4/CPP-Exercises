//We'll use a pointer to change other value
#include <iostream>

int main(){
  int x;
  int *xptr = &x;
  *xptr = 100;

  std::cout << "x value is: " << x << std::endl;
  return 0;
}
