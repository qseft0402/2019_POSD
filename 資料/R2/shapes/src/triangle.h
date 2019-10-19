#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>

class Triangle : public Shape
{
    public:
        Triangle(double x1, double y1, double x2, double y2, double x3, double y3) : _x1(x1), _x2(x2), _x3(x3), _y1(y1), _y2(y2), _y3(y3)
        {
            if (0.5 * abs((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3)) == 0)
            {
                throw std::string("Not a triangle.");
            }
        }

        double area() const
        {
            return 0.5 * abs((_x1 * _y2 + _x2 * _y3 + _x3 * _y1) - (_x2 * _y1 + _x3 * _y2 + _x1 * _y3));
        }

        double perimeter() const
        {
            return this->pointDistance(_x1, _y1, _x2, _y2) +
                   this->pointDistance(_x1, _y1, _x3, _y3) +
                   this->pointDistance(_x2, _y2, _x3, _y3);
        }

        bool isTriangle() const
        {
            return this->area() != 0;
        }

    private:
        double _x1;
        double _x2;
        double _x3;
        double _y1;
        double _y2;
        double _y3;

        double pointDistance(double x1, double y1, double x2, double y2) const
        {
            return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        }
};

#endif