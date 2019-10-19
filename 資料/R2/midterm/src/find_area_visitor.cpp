#include "find_area_visitor.h"
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "ellipse.h"
#include "complex_shapes.h"

FindAreaVisitor::FindAreaVisitor(double min, double max) : _min(min), _max(max), _isChildCall(false), _results(std::vector<Shape *>{})
{
}

void FindAreaVisitor::visitCircle(Circle *circle)
{
}

void FindAreaVisitor::visitRectangle(Rectangle *rectangle)
{
}

void FindAreaVisitor::visitEllipse(Ellipse *ellipse)
{
}

void FindAreaVisitor::visitComplexShapes(ComplexShapes *complexShapes)
{
    if (!this->_isChildCall)
    {
        this->_results = std::vector<Shape *>{};
    }

    for(int i = 0; i < complexShapes->numberOfChild(); i++)
    {
        if (this->_min <= complexShapes->getChild(i)->area() && complexShapes->getChild(i)->area() <= this->_max)
        {
            this->_results.push_back(complexShapes->getChild(i));
        }

        this->_isChildCall = true;
        complexShapes->getChild(i)->accept(this);
    }

    this->_isChildCall = false;
}

std::vector<Shape*> FindAreaVisitor::findResult()
{
    return this->_results;
}