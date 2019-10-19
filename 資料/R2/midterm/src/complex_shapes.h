#ifndef COMPLEX_SHAPES_H
#define COMPLEX_SHAPES_H

#include "shape.h"
#include "find_area_visitor.h"
#include <vector>

class ComplexShapes : public Shape
{
  public:
    ComplexShapes(std::vector<Shape *> *shapes);
    void add(Shape *shape);
    double area() const;
    double perimeter() const;
    Shape *getChild(int index);
    int numberOfChild();
    void accept(FindAreaVisitor *fav);

  private:
    std::vector<Shape *> *_shapes;
};

#endif