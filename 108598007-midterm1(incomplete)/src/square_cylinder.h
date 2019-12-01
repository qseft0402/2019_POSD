#ifndef SQUARE_CYLINDER_H
#define SQUARE_CYLINDER_H
#include "solid.h"
class SquareCylinder:public Solid
{
  public:
    SquareCylinder(double edge, double height):_edge(edge),_height(height){

    }
    double bottomArea()const{


      return this->_edge*this->_edge;
    }
    double volume()const{

      return bottomArea()*_height;
    }


  private:
    double _edge,_height;
};
#endif
