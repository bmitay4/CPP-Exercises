//Exmaple of filling an array and printing its values;
//Note, I've chose not to using namespace std explicitly
#include <iostream>

int main(){
  //Decleration of an array, size 5
  int myArr[5];

  //Fill the array
  for (size_t i = 0; i < 5; i++) {
    std::cout << "Enter a value for index " << i << '\n';
    std::cin >> myArr[i];
  }

  //Print the values
  for (size_t i = 0; i < 5; i++) {
    std::cout << "Value at index " << i << ": " << myArr[i] << std::endl;
  }

  return 0;
}
