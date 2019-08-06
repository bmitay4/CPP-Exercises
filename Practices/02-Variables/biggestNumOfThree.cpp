//Exercise that return the biggest number out of three
#include <iostream>
using namespace std;

int main(){
  int x, y, z;
  cout << "Enter 3 numbers\n";
  cin >> x;
  cin >> y;
  cin >> z;
  if(x > y && x > z) cout << "Biggest number is:\t" << x << endl;
  else if(y > x && y > z) cout << "Biggest number is:\t" << y << endl;
  else if(z > y && z > y) cout << "Biggest number is:\t" << z << endl;
  else
    cout << "Two numbers or more have the same value\n";

  return 0;
}
