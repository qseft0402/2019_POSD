#ifndef CIRCULARSECTOR_H
#define CIRCULARSECTOR_H

#include <cmath>
#include "shape.h"
class CircularSector:public Shape
{
public:
    CircularSector(double radius, double degree):_radius(radius), _degree(degree){}
    double sumOfSquares() const{
      return pow(area(),2)+pow(perimeter(),2);
    }

    double area() const{
    // cout<< "area()="<<_radius*_radius*M_PI*_degree/360.0<<endl;
    return _radius*_radius*M_PI*_degree/360.0;
    }
    double perimeter() const{
      double ans;
      ans=2*this->_radius*M_PI*(this->_degree/360.0)+2*this->_radius;
      return ans;
    }
  private:
  double _radius=0;
  double _degree=0;
  // double _a=-1,_p=-1;
};
#endif
