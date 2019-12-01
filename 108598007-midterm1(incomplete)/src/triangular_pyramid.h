#ifndef TRIANGULAR_PYRAMID_H
#define TRIANGULAR_PYRAMID_H
#include "solid.h"
#include "cmath"
#include "string"
using namespace std;
class TriangularPyramid:public Solid
{
  public:
    struct Point
    {
      double x;
      double y;
    };


    TriangularPyramid(double x1, double y1, double x2, double y2, double x3, double y3, double height):_x1(x1), _x2(x2), _x3(x3), _y1(y1), _y2(y2), _y3(y3),_height(height){
     _p1.x=x1;
     _p1.y=y1;
     _p2.x=x2;
     _p2.y=y2;
     _p3.x=x3;
     _p3.y=y3;
      setLength();

      if(!(_a+_b>_c && _b+_c>_a && _a+_c>_b) ){
        throw string("Bottom is not a Triangle!");
      }

      _s=(_a+_b+_c)/2;
    }
    double bottomArea()const{
      return sqrt(_s*(_s-_a)*(_s-_b)*(_s-_c));
    }
    double volume()const{

      return bottomArea()*_height/3.0;
    }
    void setLength() {
    this->_a=length(this->_p1,this->_p2);
    this->_b=length(this->_p2,this->_p3);
    this->_c=length(this->_p3,this->_p1);
    }

    double length(Point p1,Point p2) const{//計算長度
         double ll1=abs(p1.x-p2.x);
         double ll2=abs(p1.y-p2.y);
         return pythagorean(ll1,ll2);
       }
     double pythagorean(double l1,double l2) const{//勾股定理
       return (double)sqrt((double)pow(l1,2)+(double)pow(l2,2));
     }
     // vector<Solid*> find(double volumeMin,double volumeMax,double bottomAreaMin,double bottomAreaMax){
     //   vector<Solid*> vec;
     //   return vec;
     // }

    double _a,_b,_c;
    double _x1=0;
     double _x2=0;
     double _x3=0;
     double _y1=0;
     double _y2=0;
     double _y3=0;
     struct Point _p1,_p2,_p3;
    double _s;
    double _height;

};
#endif
