#ifndef circle_h
#define circle_h

#include "shape.h"
#include<math.h>

class Circle:public Shape
{
public:
  Circle(double r):_r(r)
  {

  }

  double area() const
  {
    return M_PI * _r * _r;
  }

  double perimeter() const
  {
    return 2 * M_PI * _r;
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
  double _r;
};
#endif /* circle_h */
