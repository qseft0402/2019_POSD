#include <gtest/gtest.h>
#include "../src/circle.h"
#include "../src/triangle.h"
#include "../src/rectangle.h"
#include "../src/sort.h"

TEST (ShapeTest, SortingLambda)
{
    std::vector<Shape*>* shapes = new std::vector<Shape*>
    {
        new Circle(1.0),
        new Circle(0.5),
        new Rectangle(5.0, 6.0),
        new Rectangle(0.5, 1.5)
    };

    Sort* sort = new Sort(shapes);
    sort->sortArea([](Shape* a, Shape* b)
    {
        return a->area() < b->area();
    });

    ASSERT_NEAR(0.75, (*shapes)[0]->area(), 0.001);
    ASSERT_NEAR(0.25*3.1415, (*shapes)[1]->area(), 0.001);
    ASSERT_NEAR(3.1415, (*shapes)[2]->area(), 0.001);
    ASSERT_NEAR(30, (*shapes)[3]->area(), 0.001);

    delete shapes;
    delete sort;
}

TEST (ShapeSorting, PerimeterAscending)
{
    std::vector<Shape*>* shapes = new std::vector<Shape*>
    {
        new Circle(10.0),
        new Rectangle(5.0, 6.0),
        new Rectangle(2.0, 3.0),
        new Triangle(0.0, 0.0, 3.0, 0.0, 0.0, 4.0)
    };

    Sort* sort = new Sort(shapes);
    sort->sortPerimeter(perimeterAscendingComparison);

    ASSERT_NEAR(10.0, (*shapes)[0]->perimeter(), 0.01);
    ASSERT_NEAR(12.0, (*shapes)[1]->perimeter(), 0.01);
    ASSERT_NEAR(22.0, (*shapes)[2]->perimeter(), 0.01);
    ASSERT_NEAR(62.83, (*shapes)[3]->perimeter(), 0.01);

    delete shapes;
    delete sort;
}

TEST (ShapeSorting, PerimeterDescending)
{
    std::vector<Shape*>* shapes = new std::vector<Shape*>
    {
        new Circle(10.0),
        new Rectangle(5.0, 6.0),
        new Rectangle(2.0, 3.0),
        new Triangle(0.0, 0.0, 3.0, 0.0, 0.0, 4.0)
    };

    Sort* sort = new Sort(shapes);
    sort->sortPerimeter(perimeterDescendingComparison);

    ASSERT_NEAR(62.83, (*shapes)[0]->perimeter(), 0.01);
    ASSERT_NEAR(22.0, (*shapes)[1]->perimeter(), 0.01);
    ASSERT_NEAR(12.0, (*shapes)[2]->perimeter(), 0.01);
    ASSERT_NEAR(10.0, (*shapes)[3]->perimeter(), 0.01);

    delete shapes;
    delete sort;
}

TEST (ShapeSorting, CompactnessAscending)
{
    std::vector<Shape*>* shapes = new std::vector<Shape*>
    {
        new Circle(10.0),
        new Rectangle(5.0, 6.0),
        new Rectangle(2.0, 3.0),
        new Triangle(0.0, 0.0, 3.0, 0.0, 0.0, 4.0)
    };

    Sort* sort = new Sort(shapes);
    sort->sortCompactness(CompactnessAscendingComparison());

    ASSERT_NEAR(12.566, (*shapes)[0]->compactness(), 0.01);
    ASSERT_NEAR(16.13, (*shapes)[1]->compactness(), 0.01);
    ASSERT_NEAR(16.67, (*shapes)[2]->compactness(), 0.01);
    ASSERT_NEAR(24, (*shapes)[3]->compactness(), 0.01);

    delete shapes;
    delete sort;
}

TEST (ShapeSorting, CompactnessDescending)
{
    std::vector<Shape*>* shapes = new std::vector<Shape*>
    {
        new Circle(10.0),
        new Rectangle(5.0, 6.0),
        new Rectangle(2.0, 3.0),
        new Triangle(0.0, 0.0, 3.0, 0.0, 0.0, 4.0)
    };

    Sort* sort = new Sort(shapes);
    sort->sortCompactness(CompactnessDescendingComparison());

    ASSERT_NEAR(24, (*shapes)[0]->compactness(), 0.01);
    ASSERT_NEAR(16.67, (*shapes)[1]->compactness(), 0.01);
    ASSERT_NEAR(16.13, (*shapes)[2]->compactness(), 0.01);
    ASSERT_NEAR(12.566, (*shapes)[3]->compactness(), 0.01);
}