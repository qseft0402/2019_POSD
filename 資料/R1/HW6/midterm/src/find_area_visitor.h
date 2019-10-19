#ifndef FIND_AREA_VISITOR_H
#define FIND_AREA_VISITOR_H

#include <iostream>
#include <vector>

class Shape;
class Circle;
class Ellipse;
class Rectangle;
class ComplexShapes;

using namespace std;

class FindAreaVisitor {
public:
    FindAreaVisitor(double min, double max);

    void visit(ComplexShapes *);

    vector<Shape*> findResult();

private:
  double _min, _max;
  vector<Shape*> favVector;

};
#endif
