#include <gtest/gtest.h>
#include "../src/triangle.h"
#include "../src/circular_sector.h"
#include "../src/ellipse.h"
#include <stdexcept>
// #include "../src/ellipse.h"
#include <algorithm>

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST (ShapeTest, first)
{
  ASSERT_TRUE(true);
}

// TEST (ShapeTest, Triangle)
// {
//   Triangle r(0,0,3,0,3,4);
//   ASSERT_NEAR(6, r.area(), 0.001);
//   ASSERT_NEAR(12, r.perimeter(), 0.001);
// }

TEST (ShapeTest, Triangle)
{
  Triangle r(0,0,5,0,5,5);
  ASSERT_NEAR(12.5, r.area(), 0.001);
  ASSERT_NEAR(17.0711, r.perimeter(), 0.001);
}

// TEST (ShapeTest, Triangle)
// {
//   Triangle r(0,0,0,10,0,5);
//   ASSERT_NEAR(12.5, r.area(), 0.001);
//   ASSERT_NEAR(17.0711, r.perimeter(), 0.001);
// }


TEST (ShapeTest, CircularSector)
{
  CircularSector c(10,60);
  ASSERT_NEAR(52.3599, c.area(), 0.001);
  ASSERT_NEAR(30.471975, c.perimeter(), 0.001);
}


TEST (ShapeTest, Ellipse)
{
  Ellipse e(10,5);
  ASSERT_NEAR(157.07963, e.area(), 0.001);
  ASSERT_NEAR(51.41593, e.perimeter(), 0.001);
}

// TEST(ShapeTest, Sorting)
// {
//   Shape* test_array[4] = {new Circle(1.0), new Circle(0.5), new Rectangle(5, 6), new Rectangle(0.5, 1.5)};
//
//   std::sort(test_array, test_array+4, [](Shape * a, Shape *b) {
//     return a->area() < b->area();
//   });
//   ASSERT_NEAR(0.75, test_array[0]->area(), 0.001);
//   ASSERT_NEAR(0.25*3.1415, test_array[1]->area(), 0.001);
//   ASSERT_NEAR(3.1415, test_array[2]->area(), 0.001);
//   ASSERT_NEAR(30, test_array[3]->area(), 0.001);
// }
