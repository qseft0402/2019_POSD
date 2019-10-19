#ifndef FIND_AREA_VISITOR_H
#define FIND_AREA_VISITOR_H

#include <vector>

class Shape;
class Circle;
class Rectangle;
class Ellipse;
class ComplexShapes;

class FindAreaVisitor {
public:
    FindAreaVisitor(double min, double max);
    void visitCircle(Circle* circle);
    void visitRectangle(Rectangle* rectangle);
    void visitEllipse(Ellipse* ellipse);
    void visitComplexShapes(ComplexShapes* complexShapes);
    std::vector<Shape*> findResult();

private:
    std::vector<Shape*> _results;
    bool _isChildCall;
    double _min;
    double _max;
};
#endif