#ifndef TRIANGLE_H
#define TRIANGLE_H


#include <iostream>
using namespace std;
#include <cmath>
#include <stdexcept>

#include "shape.h"
class Triangle:public Shape
{

public:
  struct Point
  {
    double x;
    double y;
  };

    Triangle(double x1, double y1, double x2, double y2, double x3, double y3) :_x1(x1), _x2(x2), _x3(x3), _y1(y1), _y2(y2), _y3(y3){
      _p1.x=x1;
      _p1.y=y1;
      _p2.x=x2;
      _p2.y=y2;
      _p3.x=x3;
      _p3.y=y3;
      setLength();
      if(!((_l1+_l2)>_l3 & (_l1+_l3)>_l2 & (_l3+_l2)>_l1)){

          this->run=false;
          throw string ("Not a IsoscelesTriangle.");
      }
      if(!isIsoscelesTriangle()) {
        this->run=false;
        throw  string("Not a IsoscelesTriangle.");
      }
    }
    double sumOfSquares() const{
      return pow(area(),2)+pow(perimeter(),2);
    }

    double area() const{
      if(run) return abs(_x1*_y2+_x2*_y3+_x3*_y1-_y1*_x2-_y2*_x3-_y3*_x1)/2.0;
      else return -1;
    }
    double perimeter() const{
      if(run) return this->_l1+this->_l2+this->_l3;
      else return -1;
    }


    bool isIsoscelesTriangle() const{
      if(this->_l1==this->_l2) return true;
      else if(this->_l2==this->_l3) return true;
      else if(this->_l3==this->_l1) return true;
      else return false;
    }
    void setLength() {
      this->_l1=length(this->_p1,this->_p2);
      this->_l2=length(this->_p2,this->_p3);
      this->_l3=length(this->_p3,this->_p1);
    }
    double length(Point p1,Point p2) const{//計算長度
      double ll1=abs(p1.x-p2.x);
      double ll2=abs(p1.y-p2.y);
      return pythagorean(ll1,ll2);
    }
    double pythagorean(double l1,double l2) const{//勾股定理
      return (double)sqrt((double)pow(l1,2)+(double)pow(l2,2));
    }

  double _x1=0;
  double _x2=0;
  double _x3=0;
  double _y1=0;
  double _y2=0;
  double _y3=0;
  double _l1=0,_l2=0,_l3=0;
  double temp=0;
  bool run=true;
  struct Point _p1,_p2,_p3;
};
#endif
