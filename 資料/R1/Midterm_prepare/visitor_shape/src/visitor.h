#ifndef VISITOR_H
#define VISITOR_H

#include <vector>
#include <string>

using namespace std;

class Shape;
class Circle;
class Triangle;
class Rectangle;

class Visitor{
  public:
    Visitor(){}

    virtual void visitCircle(Circle *circle) = 0;
    virtual void visitTriangle(Triangle *triangle) = 0;
    virtual void visitRectangle(Rectangle *rectangle) = 0;

    virtual double area() const{};
    virtual double perimeter() const{};
  private:
};

#endif
