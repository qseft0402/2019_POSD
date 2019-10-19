#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include "visitor.h"
#include <math.h>

class Rectangle:public Shape
{
public:
  Rectangle(){}

  void setRadius(double Iwa1, double Iwa2)
  {
      _r1 = Iwa1;
      _r2 = Iwa2;
  }

  void getRadius(double &rr1, double &rr2) const
  {
      rr1 = _r1;
      rr2 = _r2;
  }
  void accept(Visitor *visitor)
  {
    visitor->visitRectangle(this);
  }

private:
  double _r1, _r2;
};
#endif /* rectangle_h */
