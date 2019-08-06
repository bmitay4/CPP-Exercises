//Rectangle header file
#include "Point.hpp"
class Rectangle{
private:
  int itsTop;
  int itsBottom;
  int itsLeft;
  int itsRight;
  Point itsUpperLeft;
  Point itsUpperRight;
  Point itsBottomRight;
  Point itsBottomLeft;
public:
  Rectangle(int top, int left, int bottom, int right); //init constructor
  ~Rectangle();
  int getTop() const {return itsTop;}
  int getBottom() const {return itsBottom;}
  int getLeft() const {return itsLeft;}
  int getRight() const {return itsRight;}

  void setTop(int value) {itsTop = value;}
  void setBottom(int value) {itsBottom = value;}
  void setLeft(int value) {itsLeft = value;}
  void setRight(int value) {itsRight = value;}

  Point getUpperLeft() const {return itsUpperLeft;}
  Point getUpperRight() const {return itsUpperRight;}
  Point getBottomLeft() const {return itsBottomLeft;}
  Point getBottomRight() const {return itsBottomRight;}

  void setUpperLeft(Point value) {itsUpperLeft = value;}
  void setUpperRight(Point value) {itsUpperRight = value;}
  void setBottomLeft(Point value) {itsBottomLeft = value;}
  void setBottomRight(Point value) {itsBottomRight = value;}

  int getArea() const;
};
Rectangle::~Rectangle(){
}
