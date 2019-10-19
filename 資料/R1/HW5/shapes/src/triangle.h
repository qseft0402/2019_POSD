#ifndef triangle_h
#define triangle_h

#include "shape.h"
#include<math.h>
#include<string>
#include "string.h"
#include <iostream>
using namespace std;

class Triangle:public Shape
{
public:
  double _r1, _r2, _r3; //3邊長
  Triangle(double x1, double y1, double x2, double y2, double x3, double y3):_x1(x1), _x2(x2), _x3(x3), _y1(y1), _y2(y2), _y3(y3)
  {
    _r1 = sqrt( pow(x1 - x2, 2) + pow(y1 - y2, 2) );
    _r2 = sqrt( pow(x1 - x3, 2) + pow(y1 - y3, 2) );
    _r3 = sqrt( pow(x3 - x2, 2) + pow(y3 - y2, 2) );
    if(_r1 + _r2 > _r3 && _r1 + _r3 > _r2 && _r2 + _r3 > _r1)
    {
          //cout << "QQ" << endl;
    }
    else
    {
      //throw "Not a triangle";
      throw std::string("Not a triangle.");
    }
  }

  double area() const
  {
    double s=0.5*(_r1 + _r2 + _r3);
    return sqrt(s*(s-_r1)*(s-_r2)*(s-_r3));
  }

  double perimeter() const
  {
    return _r1 + _r2 + _r3;
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
  double _x1, _x2, _x3; //傳入x座標
  double _y1, _y2, _y3; //傳入y座標


};
#endif /* triangle_h */
