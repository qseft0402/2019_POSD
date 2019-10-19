#include "complex_shapes.h"

ComplexShapes::ComplexShapes(std::vector<Shape *> *shapes) : _shapes(shapes)
{
}

void ComplexShapes::add(Shape *shape)
{
    this->_shapes->push_back(shape);
}

double ComplexShapes::area() const
{
    double result = 0.0;

    for (Shape *shape : *(this->_shapes))
    {
        result += shape->area();
    }

    return result;
}

double ComplexShapes::perimeter() const
{
    double result = 0.0;

    for (Shape *shape : *(this->_shapes))
    {
        result += shape->perimeter();
    }

    return result;
}

Shape *ComplexShapes::getChild(int index)
{
    return (*(this->_shapes))[index];
}

int ComplexShapes::numberOfChild()
{
    return this->_shapes->size();
}

void ComplexShapes::accept(FindAreaVisitor *fav)
{
    fav->visitComplexShapes(this);
}
