#ifndef CONE_H
#define CONE_H
#include "string"
using namespace std;
#include <cmath>
#include "solid.h"
class Cone:public Solid
{

public:
  struct Point
  {
    double x;
    double y;
  };
    Cone(double x1,double y1,double x2,double y2, double height):_height(height){

      _p1.x=x1;
      _p1.y=y1;
      _p2.x=x2;
      _p2.y=y2;
      _radius=length(_p1,_p2);
      if(_radius==0)
        throw string("Bottom is not a Circle!");

    }
    double bottomArea()const{

      return this->_radius*this->_radius*M_PI;
    }
    double volume()const{

      return bottomArea()*_height/3.0;
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
private:
  double  _radius,_height;
  struct Point _p1,_p2;
};
#endif
