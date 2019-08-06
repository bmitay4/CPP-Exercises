#include "Rectangle.hpp"

Rectangle::Rectangle(int top, int left, int bottom, int right){
  itsTop = top;
  itsBottom = bottom;
  itsLeft = left;
  itsRight = right;

  itsUpperLeft.setX(left);
  itsUpperLeft.setY(top);
  itsUpperRight.setX(right);
  itsUpperRight.setY(top);
  itsBottomLeft.setX(left);
  itsBottomLeft.setY(bottom);
  itsBottomRight.setX(left);
  itsBottomRight.setY(right);
}
int Rectangle::getArea() const{
  int height = itsRight - itsLeft;
  int width = itsTop - itsBottom;
  return (height*width);
}
int main(){
  Rectangle myRec(100,20,50,80);

  int Area = myRec.getArea();
  cout << "Area:" << Area << endl;
  cout << myRec.getUpperLeft().getX() << endl;
  return 0;
}
