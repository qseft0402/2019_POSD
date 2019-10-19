#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape
{
    public:
        Rectangle(double l, double w) : _l(l), _w(w)
        {
        }

        bool isRectangle() const
        {
            return _l > 0 && _w > 0;
        }

        double area() const
        {
            return this->isRectangle() ? _l * _w : 0;
        }

        double perimeter() const
        {
            return this->isRectangle() ? (_l + _w) * 2 : 0;
        }

    private:
        double _l;
        double _w;
};

#endif