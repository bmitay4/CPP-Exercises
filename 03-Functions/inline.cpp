//Exmaple for using inline function
#include <iostream>
using namespace std;

inline int DoubleNum(int value);

inline int DoubleNum(int value){
  return 2*value;
}
int main(){
  int num;
  cout << "Enter a value to work with\n";
  cin >> num;
  num = DoubleNum(num);
  cout << "Current value:\t" << num << endl;
  num = DoubleNum(num);
  cout << "Current value:\t" << num << endl;
  num = DoubleNum(num);
  cout << "Current value:\t" << num << endl;
  return 0;
}
