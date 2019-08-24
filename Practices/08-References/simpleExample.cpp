//Using references, both at varibales and functions
#include <iostream>
using namespace std;

void swap(int &x, int &y);

void swap(int &x, int &y){
  int temp = x;
  x = y;
  y = temp;
}

int main(){
  int x = 10;
  int &rx = x;
  cout << "x value is: " << x << endl;
  cout << "rx value is: " << rx << endl;

  //Now we'll change rx value, and see what happend to the orirignal variable
  rx = 95;
  cout << "x value is: " << x << endl;
  cout << "rx value is: " << rx << endl;

  //Swap function, using references
  int y = 34;
  cout << "x value before swap is: " << x << endl;
  cout << "y value before swap is: " << y << endl;

  swap(x, y);
  cout << "x value is: " << x << endl;
  cout << "y value is: " << y << endl;

  return 0;
}
