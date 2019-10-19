#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <math.h>
#include "shape.h"

class Ellipse : public Shape
{
  public:
    Ellipse(double a, double b) : _a(a), _b(b)
    {
    }

    double area() const
    {
        return M_PI * this->_a * this->_b;
    }

    double perimeter() const
    {
        return 2 * M_PI * sqrt((pow(this->_a, 2) + pow(this->_b, 2)) * 0.5);
    }

    void accept(FindAreaVisitor *fav)
    {
        fav->visitEllipse(this);
    }

  private:
    double _a;
    double _b;
};

#endif