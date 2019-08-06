//Example of using enum
//The first element has a value, and the rest elements increased by 1 consecutively
#include <iostream>
using namespace std;
enum Days {
  Sunday = 1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
};
//We set the first element to be 1, so the second element is 2 etc
int main(){
  int choice;
  cout << "Enter a day (1-7)" << endl;
  cin >> choice; //use cin to get input from the keyborad
  if(choice == Friday || choice == Saturday)
    cout << "Holiday!" << endl;
  else
    cout << "Probobly at work" << endl;
  return 0;
}
