#ifndef SQUARE_CYLINDER_H
#define SQUARE_CYLINDER_H
#include "solid.h"
class SquareCylinder : public Solid{
public:
  SquareCylinder(double edge, double height): _edge(edge),_height(height){}
  double bottomArea()const{
    return _edge*_edge;
  }
  double volume() const{
    return bottomArea()*_height;
  }
  bool isComplexSolids(){
    return false;
  }
  int numberOfChild(){
    return 0;
  }
private:
  double _edge;
  double _height;
};
#endif
