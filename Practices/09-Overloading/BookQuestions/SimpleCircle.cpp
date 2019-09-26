#include "SimpleCircle.hpp"

//newLine function, just for better printing to screen
void newLine();

void newLine(){
  cout << "#---------------------#";
  cout << endl;
}

int main(){
  cout << "Create two instance of SimpleCircle" << endl;
  SimpleCircle circle1, circle2(9);
  newLine();

  cout << "Printing the Circles's radius\n";
  cout << "Circle 1 radius value: " << circle1.getRadius() << endl;
  cout << "Circle 2 radius value: " << circle2.getRadius() << endl;
  newLine();

  //postfix test
  circle1++;
  circle2++;
  newLine();
  cout << "Printing the Circles's radius, after postfix test\n";
  cout << "Circle 1 radius value: " << circle1.getRadius() << endl;
  cout << "Circle 2 radius value: " << circle2.getRadius() << endl;

  newLine();
  //prefix text
  ++circle1;
  ++circle2;
  cout << "Printing the Circles's radius, after prefix text\n";
  cout << "Circle 1 radius value: " << circle1.getRadius() << endl;
  cout << "Circle 2 radius value: " << circle2.getRadius() << endl;
  newLine();

  cout << "Assigning SimpleCircle's instance (NO changes)" << endl;
  circle1 = circle1;
  cout << "Circle 1 radius value: " << circle1.getRadius() << endl;
  newLine();

  cout << "Assigning SimpleCircle's instance" << endl;
  circle1 = circle2;
  cout << "Circle 1 radius value: " << circle1.getRadius() << endl;
  newLine();

  return 0;
}
