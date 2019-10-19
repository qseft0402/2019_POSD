#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include "visitor.h"
#include "string.h"
#include<math.h>
#include<string>
#include <iostream>
using namespace std;

class Triangle:public Shape
{
public:
  Triangle(){}

  void setRadius(double x1, double y1, double x2, double y2, double x3, double y3)
  {
      _x1=x1;
      _x2=x2;
      _x3=x3;
      _y1=y1;
      _y2=y2;
      _y3=y3;

      _r1 = sqrt( pow(_x1 - _x2, 2) + pow(_y1 - _y2, 2) );
      _r2 = sqrt( pow(_x1 - _x3, 2) + pow(_y1 - _y3, 2) );
      _r3 = sqrt( pow(_x3 - _x2, 2) + pow(_y3 - _y2, 2) );

        if(_r1 + _r2 > _r3 && _r1 + _r3 > _r2 && _r2 + _r3 > _r1)
        {
        }
        else
        {
          throw std::string("Not a triangle.");
        }
  }

  void getRadius(double &rr1, double &rr2, double &rr3) const
  {
      rr1 = _r1;
      rr2 = _r2;
      rr3 = _r3;
  }
  void accept(Visitor *visitor)
  {
    visitor->visitTriangle(this);
  }
private:
  double _x1, _x2, _x3; //傳入x座標
  double _y1, _y2, _y3; //傳入y座標
  double _r1, _r2, _r3; //3邊長


};
#endif /* triangle_h */
