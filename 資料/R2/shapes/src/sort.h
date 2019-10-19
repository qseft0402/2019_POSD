#ifndef SORT_H
#define SORT_H

#include <algorithm>
#include <functional>
#include <vector>
#include "shape.h"

bool perimeterDescendingComparison(Shape* a, Shape* b);

bool perimeterAscendingComparison(Shape* a, Shape* b);

class CompactnessAscendingComparison;

class CompactnessDescendingComparison;

// Sort util class
class Sort
{
    public:
        Sort(std::vector<Shape*>* shapes) : _shapes(shapes)
        {
        }

        void sortArea(std::function<bool (Shape*, Shape*)> compare)
        {
            std::sort(this->_shapes->begin(), this->_shapes->end(), compare);
        }

        void sortPerimeter(std::function<bool (Shape*, Shape*)> compare)
        {
            std::sort(this->_shapes->begin(), this->_shapes->end(), compare);
        }

        void sortCompactness(std::function<bool (Shape*, Shape*)> compare)
        {
            std::sort(this->_shapes->begin(), this->_shapes->end(), compare);
        }

    private:
        std::vector<Shape*>* _shapes;
};

std::function<bool (Shape*, Shape*)> sortAreaDesc = [](Shape* a, Shape* b)
{
    return a->area() > b->area();
};

std::function<bool (Shape*, Shape*)> sortAreaAsc = [](Shape* a, Shape* b)
{
    return a->area() < b->area();
};

bool perimeterDescendingComparison(Shape* a, Shape* b)
{
    return a->perimeter() > b->perimeter();
}

bool perimeterAscendingComparison(Shape* a, Shape* b)
{
    return a->perimeter() < b->perimeter();
}

class CompactnessAscendingComparison
{
    public:
        CompactnessAscendingComparison()
        {
        }

        bool operator()(Shape* a, Shape* b)
        {
            return a->compactness() < b->compactness();
        }
};

class CompactnessDescendingComparison
{
    public:
        CompactnessDescendingComparison()
        {
        }

        bool operator()(Shape* a, Shape* b)
        {
            return a->compactness() > b->compactness();
        }
};

#endif