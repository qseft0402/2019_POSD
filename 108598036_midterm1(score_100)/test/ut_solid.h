#include <gtest/gtest.h>
#include "../src/solid.h"
#include "../src/cone.h"
#include "../src/square_cylinder.h"
#include "../src/triangular_pyramid.h"
#include "../src/complex_solids.h"
TEST (SolidTest, TriangularPyramidCalculate)
{
  TriangularPyramid tp(0.0, 0.0, 4.0, 0.0, 4.0, 3.0,5.0);
  ASSERT_NEAR(6,tp.bottomArea(), 0.001);
  ASSERT_NEAR(10,tp.volume(), 0.001);

}
TEST (SolidTest, TriangularPyramidException)
{
  try{
    TriangularPyramid tp(0.0, 0.0, 0.0, 0.0, 0.0, 0.0,5.0);
    ASSERT_EQ(true, false);
  } catch(std::string s){

    ASSERT_EQ("Bottom is not a Triangle!", s);
  }

}


TEST (SolidTest, ConeCalculate)
{
  Cone c(0,0,2,0,5);
  ASSERT_NEAR(12.566,c.bottomArea(), 0.001);
  ASSERT_NEAR(20.943,c.volume(), 0.001);

}
TEST (SolidTest, ConeException)
{
  try{
    Cone c(0,0,0,0,5);
    ASSERT_EQ(true, false);
  } catch(std::string s){

    ASSERT_EQ("Bottom is not a Circle!", s);
  }

}
TEST (SolidTest, SquareCylinderCaculate)
{
  SquareCylinder ss(2.0,5.0);
  ASSERT_NEAR(4,ss.bottomArea(), 0.001);
  ASSERT_NEAR(20,ss.volume(), 0.001);

}


TEST (SolidTest, ComplexSolidsTest)
{
  SquareCylinder s(2.0,5.0);
  Cone c(0,0,2,0,5);
  vector<Solid*> * solids = new vector<Solid*>();
  ComplexSolids com(solids);
  com.add(&s);
  com.add((&c));
  ASSERT_EQ(2,com.numberOfChild());
  // 2 points
  // Test numberOfChild of ComplexSolids
}

TEST (SolidTest, ComplexSolidsCalculate)
{
  SquareCylinder s(2.0,5.0);
  Cone c(0,0,2,0,5);
  vector<Solid*> * solids = new vector<Solid*>();
  ComplexSolids com(solids);
  com.add(&s);
  com.add((&c));
  ASSERT_NEAR(16.566,com.bottomArea(), 0.001);
  ASSERT_NEAR(40.943,com.volume(), 0.001);
  // 2 points
  // Test bottomArea() and volume() of ComplexSolids
}


TEST (SolidTest, findBySolid){
  vector<Solid*> final;

  Cone c(0,0,2,0,5);
  // final.push_back(&c);
  ASSERT_EQ(final,c.find(15,16,10,20));
  final.clear();

  SquareCylinder s(2.0,5.0);
  final.push_back(&s);
  ASSERT_EQ(final,s.find(15,25,2,6));
  final.clear();

  TriangularPyramid tp(0.0, 0.0, 4.0, 0.0, 4.0, 3.0,5.0);
  final.push_back(&tp);
  ASSERT_EQ(final,tp.find(10,20,2,8));
  final.clear();
  // 5 points
  // Test find() method of cone and TriangularPyramid and SquareCylinder
}

TEST (SolidTest, findByComplextSolids){
  SquareCylinder s(2.0,5.0);
  Cone c(0,0,2,0,5);
  TriangularPyramid tp(0.0, 0.0, 4.0, 0.0, 4.0, 3.0,5.0);
  vector<Solid*> * solids = new vector<Solid*>();
  vector<Solid*> * solids2 = new vector<Solid*>();
  ComplexSolids com(solids);
  ComplexSolids com2(solids2);

  com.add(&s);
  com2.add((&c));
  com.add((&tp));
  com.add(&com2);
  vector<Solid*> final;
  final.push_back(&s);
  final.push_back(&c);
  // final.push_back(&tp);
  ASSERT_EQ(final,com.find(15,25,2,20));
  // 5 points
  // Test find() method of ComplexSolids
}
