#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <math.h>
#include "find_area_visitor.h"

class Ellipse: public Shape
{
public:
    Ellipse(double a, double b):_r1(a), _r2(b)
    {

    }
    double area() const
    {
      return M_PI * _r1 * _r2;
    }
    double perimeter() const
    {
      return 2 * M_PI * sqrt((( _r1 * _r1 ) + ( _r2 * _r2 )) / 2 );
    }

  private:
    double _r1, _r2;
};

#endif
