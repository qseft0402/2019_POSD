#include "ap_visitor.h"

#include "shape.h"
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include <vector>
#include <math.h>

using namespace std;

APVisitor::APVisitor():aarea(0), pperimeter(0){}

void APVisitor::visitCircle(Circle *circle)
{
    double radius;
    circle->getRadius(radius);

    aarea = M_PI * radius * radius;
    pperimeter = 2 * M_PI * radius;
}
void APVisitor::visitTriangle(Triangle *triangle)
{
    double radius1, radius2, radius3;
    triangle->getRadius(radius1, radius2, radius3);
    double s=0.5*(radius1 + radius2 + radius3);

    aarea = sqrt(s*(s-radius1)*(s-radius2)*(s-radius3));
    pperimeter = radius1 + radius2 + radius3;
    ccompactness = pow(pperimeter,2) / aarea;
}
void APVisitor::visitRectangle(Rectangle *rectangle)
{
    double radius1, radius2;
    rectangle->getRadius(radius1, radius2);

    aarea = radius1 * radius2;
    pperimeter = 2 * (radius1 + radius2);
}
