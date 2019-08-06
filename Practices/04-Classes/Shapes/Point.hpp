//Point header file
#include <iostream>
using namespace std;
class Point{
private:
  int itsX;
  int itsY;
public:
  Point();  //default constructor
  ~Point();  //destructor
  //Note that all function defined, therefor, they are inline
  void setX(int value) {itsX = value;}
  void setY(int value) {itsY = value;}
  int getX() const {return itsX;}
  int getY() const {return itsY;}
};
Point::Point(){
  itsX = 0;
  itsY = 0;
}
Point::~Point(){
}
