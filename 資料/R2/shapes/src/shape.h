#ifndef SHAPE_H
#define SHAPE_H

#include <cmath>

class Shape
{
    public:
        virtual double area() const = 0;

        virtual double perimeter() const = 0;

        virtual double compactness() const
        {
            if (this->area() == 0)
            {
                throw std::string("Division by zero");
            }
            else
            {
                return pow(this->perimeter(), 2) / this->area();
            }
        }
};

#endif