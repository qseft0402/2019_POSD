#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>
#include "shape.h"

class Circle : public Shape
{
    public:
        Circle(double r): _r(r)
        {
        }

        bool isCircle() const
        {
            return _r > 0;
        }

        double area() const
        {
            return _r > 0 ? M_PI * this->_r * this->_r : 0;
        }

        double perimeter() const
        {
            return _r > 0 ? M_PI * 2 * this->_r : 0;
        }

    private:
        double _r;
};

#endif