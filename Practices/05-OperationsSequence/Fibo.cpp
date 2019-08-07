//Fibonacci example, iterative and recursion methods
#include <iostream>
using namespace std;

int fiboRec(int num){
  if(num <= 1) return num;
  return fiboRec(num-1) + fiboRec(num-2);
}
int fiboIterative(int num){
  int ans = 0, f1 = 0, f2 = 1;
  while(num > 1){
    ans = f1 + f2;
    f1 = f2;
    f2 = ans;
    num--;
  }
  return f2;
}
int main(){
  int value;
  cout << "Enter a requsted fibonnaci number:\n";
  cin >> value;
  cout << "Fibo by Recursion: " << fiboRec(value) << endl;
  cout << "Fibo by Loop: " << fiboIterative(value) << endl;
  return 0;
}
