#include <gtest/gtest.h>
#include <algorithm>    // std::sort
#include <string>

#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/triangle.h"
#include "../src/rectangle.h"

/*int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

first - try
TEST (ShapeTest, first)
{
  ASSERT_TRUE(true);
}
*/

TEST (ShapeTest, Circle)
{
  Shape *c = new Circle(10.0);
  ASSERT_NEAR(314.159, c->area(), 0.001);
  ASSERT_NEAR(62.831, c->perimeter(), 0.001);
}

TEST (ShapeTest, Triangle)
{
  Shape *t = new Triangle(0, 0, 0, 3, 4, 0);
  ASSERT_NEAR(6, t->area(), 0.001);
  ASSERT_NEAR(12, t->perimeter(), 0.001);
  //ASSERT_THROW(Triangle t2(0, 0, 0, -3, 0, 3), string);
  //ASSERT_THROW({
//}, std::string);
}

TEST(triangle, isTriangle)
{
  try
  {
    Shape *t2 = new Triangle(0, 0, 0, -3, 0, 3);
  }
  catch (std::string exception)
  {
    ASSERT_EQ(exception, std::string("Not a triangle."));
  }
}

TEST (ShapeTest, Rectangle)
{
  Shape *r = new Rectangle(4,5);
  ASSERT_NEAR(20, r->area(), 0.001);
  ASSERT_NEAR(18, r->perimeter(), 0.001);
}
