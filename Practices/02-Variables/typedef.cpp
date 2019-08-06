//Using typedef, also called type definition
#include <iostream>
using namespace std; //using namespace std for cout and endl
typedef unsigned short int USHORT; //using typedef saves as the need to write and define our variable each time

int main(){
  USHORT width = 5;
  USHORT length;
  length = 10;
  USHORT area = width*length;
  cout << "Width:\t" << width << endl; //endl used to insert a new-line
  cout << "Length:\t" << length << "\n"; // same as endl
  cout << "Area:\t" << area << "\n";

  return 0;
}
