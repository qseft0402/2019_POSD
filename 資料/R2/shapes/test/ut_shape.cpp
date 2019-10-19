#include <gtest/gtest.h>
#include "../src/circle.h"
#include "../src/triangle.h"
#include "../src/rectangle.h"

TEST(CircleTest, isCircle)
{
    Circle c(39.0);
    ASSERT_TRUE(c.isCircle());
}

TEST(CircleTest, isNotCircle)
{
    Circle c(-5.0);
    ASSERT_FALSE(c.isCircle());
}

TEST(CircleTest, Area)
{
    Circle c(10.0);
    ASSERT_TRUE(c.area());
    ASSERT_NEAR(314.159, c.area(), 0.01);
}

TEST(CircleTest, Perimeter)
{
    Circle c(10.0);
    ASSERT_TRUE(c.perimeter());
    ASSERT_NEAR(62.83, c.perimeter(), 0.01);
}

TEST(CircleTest, Compactness)
{
    try
    {
        Shape* s = new Circle(0.0);
        // Shape* s = new Circle(2.0);
        double compactness = s->compactness();
        ASSERT_NEAR(compactness, 12.5663, 0.001);

        delete s;
    }
    catch(std::string message)
    {
        ASSERT_EQ(message, std::string("Division by zero"));
    }
}

TEST(RectangleTest, isRectangle)
{
    Rectangle r(15.0, 3.0);
    ASSERT_TRUE(r.isRectangle());
}

TEST(RectangleTest, isNotRectangle)
{
    Rectangle r(-15.0, 3.0);
    ASSERT_FALSE(r.isRectangle());
}

TEST(RectangleTest, Area)
{
    Rectangle r(15.0, 3.0);
    ASSERT_TRUE(r.area());
    ASSERT_NEAR(45.0, r.area(), 0.01);
}

TEST(RectangleTest, Perimeter)
{
    Rectangle r(15.0, 3.0);
    ASSERT_TRUE(r.perimeter());
    ASSERT_NEAR(36.0, r.perimeter(), 0.01);
}

TEST(TriangleTest, isTriangle)
{
    Triangle t(-1.0, 1.0, -4.0, 1.0, -1.0, -0.0);
    ASSERT_TRUE(t.isTriangle());
}

TEST(TriangleTest, isNotTriangle)
{
    try
    {
        Triangle t(1.0, 1.0, 2.0, 2.0, 3.0, 3.0);
    }
    catch(const std::string message)
    {
        ASSERT_EQ(message, "Not a triangle.");
    }
}

TEST(TriangleTest, Area)
{
    Triangle t(-1.0, 1.0, -4.0, 1.0, -1.0, -0.0);
    ASSERT_TRUE(t.area());
    ASSERT_NEAR(1.5, t.area(), 0.01);
}

TEST(TriangleTest, Perimeter)
{
    Triangle t(-1.0, 1.0, -4.0, 1.0, -1.0, -3.0);
    ASSERT_TRUE(t.area());
    ASSERT_NEAR(12.0, t.perimeter(), 0.01);
}