#ifndef CONE_H
#define  CONE_H
#include <math.h>
#include <string>
#include "solid.h"
using namespace std;
class Cone :public Solid{
public:
  Cone(double x1,double y1,double x2,double y2, double height):_height(height){
    radius = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    if (radius == 0){
      throw string("Bottom is not a Circle!");
    }
  }
  double bottomArea() const{
    return radius*radius*M_PI;
  }
  double volume() const{
    return bottomArea()*_height/3;
  }
  bool isComplexSolids(){
    return false;
  }
  int numberOfChild(){
    return 0;
  }
private:
  double _x1;
  double _y1;
  double _x2;
  double _y2;
  double _height;
  double radius;
};

#endif
