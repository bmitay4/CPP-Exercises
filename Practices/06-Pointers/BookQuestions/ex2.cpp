//Same as ex1, this time we'll use function to do the math for us :)
#include <iostream>

void multiByTwo(int *num);

void multiByTwo(int *num){
  *num = 2*(*num);
}
int main(){
  int value = 101;
  multiByTwo(&value);
  std::cout << "value is: " << value << std::endl;

  return 0;
}
