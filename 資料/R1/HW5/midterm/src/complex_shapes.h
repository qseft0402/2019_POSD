#ifndef COMPLEX_SHAPES_H
#define COMPLEX_SHAPES_H

#include <iostream>
#include <vector>
#include "shape.h"
#include "find_area_visitor.h"

class FindAreaVisitor;
using namespace std;

class ComplexShapes: public Shape
{
public:
    ComplexShapes(std::vector<Shape*>*shapes);
    double area() const ;
    double perimeter() const;
    int numberOfChild() const;
    void add(Shape * sss) const;
    Shape * getChild(int index)
    {
      return _shapes1->at(index);
    }
    void accept(FindAreaVisitor *fav)
    {
      fav->visit(this);
    }
private:
    vector<Shape*>*_shapes1;

};


#endif
