#ifndef rectangle_h
#define rectangle_h

#include "shape.h"
#include<math.h>

class Rectangle:public Shape
{
public:
  Rectangle(double r1, double r2):_r1(r1), _r2(r2)
  {

  }

  double area() const
  {
    return _r1 * _r2;
  }

  double perimeter() const
  {
    return 2 * (_r1 + _r2);
  }

  double compactness() const
  {
    //Note:If Area = 0.Throw an exception string "Division by zero".
    if(this->area() == 0)
    {
      throw std::string("Division by zero");
    }

    return pow(this->perimeter(),2) / this->area();
  }

private:
  double _r1, _r2;
};
#endif /* rectangle_h */
