//Basic exmaple of using pointers and increments operation
#include <iostream>
using namespace std;

int main(){
  int x = 5;
  int *ptr_x = &x;
  cout << "x value is: " << x << endl;
  cout << "x's pointers value is: " << *ptr_x << endl;
  cout << "x address is: " << &x << endl;
  cout << "x's pointers address is: " << ptr_x << endl;

  x++;
  cout << "After increase x by 1, we'll receive:\n";
  cout << "x value is: " << x << endl;
  cout << "x's pointers value is: " << *ptr_x << endl;

  *ptr_x = 80;
  cout << "After changing *ptr_x value to 80, we'll receive:\n";
  cout << "x value is: " << x << endl;
  cout << "x's pointers value is: " << *ptr_x << endl;

  return 0;
}
