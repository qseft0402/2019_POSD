#ifndef TRIANGULAR_PYRAMID_H
#define TRIANGULAR_PYRAMID_H
#include <math.h>
#include <string>
#include "solid.h"
using namespace std;
class TriangularPyramid : public Solid{
public:
  TriangularPyramid(double x1, double y1, double x2, double y2, double x3, double y3, double height):_height(height){
    a = calculateEdge(x1,y1,x2,y2);
    b = calculateEdge(x2,y2,x3,y3);
    c = calculateEdge(x1,y1,x3,y3);
    if(!isTriangle())
      throw string("Bottom is not a Triangle!");
  }

  double bottomArea() const {
    double s = (a+b+c)/2;
    double k = s*(s-a)*(s-b)*(s-c);
    return sqrt(k);
  }
  double volume() const{
    return (bottomArea()*_height)/3;
  }
  double calculateEdge (double x1, double y1 , double x2 , double y2){
       return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
  }
  bool isComplexSolids(){
    return false;
  }
  int numberOfChild(){
    return 0;
  }
  bool isTriangle(){
    if(a+b>c && a+c>b && b+c>a)
      return true;
    else
      return false;
  }
private:
  double _height;
  double a;
  double b;
  double c;
};
#endif
