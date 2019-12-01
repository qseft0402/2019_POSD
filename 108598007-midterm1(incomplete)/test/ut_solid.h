#include <gtest/gtest.h>
#include "../src/complex_solids.h"
#include "../src/cone.h"
#include "../src/solid.h"
#include "../src/square_cylinder.h"
#include "../src/triangular_pyramid.h"

#include <algorithm>

TEST (SolidTest, first)
{
  ASSERT_TRUE(true);
}

TEST(SolidTest,ConeAreaAndVolume){
  Cone c(0,0,0,3,5);

  ASSERT_NEAR(28.2743,c.bottomArea(),0.001);
  ASSERT_NEAR(47.1238333,c.volume(),0.001);
}
TEST(SolidTest,ConeThrow){
    try{
    Cone c(0,0,0,0,5);
    ASSERT_TRUE(0);
  }catch(string s){
    ASSERT_EQ("Bottom is not a Circle!",s);

  }
}
TEST(SolidTest,SquareCylinderAreaAndVolume){
  SquareCylinder s(5,5);

  ASSERT_NEAR(25,s.bottomArea(),0.001);
  ASSERT_NEAR(125,s.volume(),0.001);
}

TEST(SolidTest,TriangularPyramidAreaAndVolume){
  TriangularPyramid t(0,0,2.5,5,0,5,5);
  ASSERT_NEAR(6.25,t.bottomArea(),0.001);
  ASSERT_NEAR(10.416666,t.volume(),0.001);
}

TEST(SolidTest,TriangularPyramidThrow){
  try{
      TriangularPyramid t(0,0,0,0,0,0,5);

    ASSERT_TRUE(0);
  }catch(string s){
    ASSERT_EQ("Bottom is not a Triangle!",s);

  }
}

TEST(SolidTest,CompleSolidsAreaAndVolume){
  std::vector<Solid*>* solid=new vector<Solid*>;
  Cone* c=new Cone(0,0,0,3,5);
  SquareCylinder* s=new SquareCylinder(5,5);
  TriangularPyramid* t=new TriangularPyramid(0,0,2.5,5,0,5,5);

  ComplexSolids* comp=new ComplexSolids(solid);
  comp->add(c);
  comp->add(s);
  comp->add(t);

  ASSERT_EQ(3,comp->numberOfChild());
  ASSERT_NEAR(59.5243,comp->bottomArea(),0.0001);
  ASSERT_NEAR(182.5404993,comp->volume(),0.0001);
}
//
TEST(SolidTest,SquareCylinderCallFind){
  TriangularPyramid* t=new TriangularPyramid(0,0,2.5,5,0,5,5);
  vector<Solid*> vec=t->find(3.6,4.2,6.3,5);
  cout<<vec.size()<<endl;
  cout<<vec[0]->bottomArea()<<endl;
  // vector<Solid*>::iterator it;
  // ASSERT_EQ(2, 1);

}






























/**/
