#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include "visitor.h"
#include <math.h>

class Circle:public Shape
{
public:
  Circle(){}

  void setRadius(double Iwa)
  {
      _r = Iwa;
  }

  void getRadius(double &rr) const
  {
      rr = _r;
  }

  void accept(Visitor *visitor)
  {
    visitor->visitCircle(this);
  }

private:
  double _r;
};
#endif /* circle_h */
