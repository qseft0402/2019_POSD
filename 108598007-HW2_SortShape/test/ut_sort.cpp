#include <gtest/gtest.h>
#include "../src/triangle.h"
#include "../src/circular_sector.h"
#include "../src/ellipse.h"
#include "../src/sort.h"
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

TEST(SortTest, sortAreaByFunctionInAscending)
{
  std::cout << "SortArea1()"<<endl;
  Shape* shape_array[] = {new CircularSector(5,4),new Triangle(0,0,5,0,5,5),new Ellipse(5,3)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
    shapeVec->push_back(shape_array[i]);

  Sort sort(shapeVec);

  function<bool(Shape* a,Shape* b)> fuc=areaAscendingComparison;
  sort.sortArea(fuc);
  std::vector<Shape*>::iterator it;
  for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
    std::cout << ' ' << (**it).area();
  std::cout << '\n';
  it=shapeVec->begin();
  ASSERT_NEAR(0.872665,(**it++).area(),0.001);
  ASSERT_NEAR(12.5,(**it++).area(),0.001);
  ASSERT_NEAR(47.1239,(**it).area(),0.001);

  fuc=areaDescendingComparison;
 sort.sortArea(fuc);

 for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
   std::cout << ' ' << (**it).area();
  std::cout << '\n';
  it=shapeVec->begin();
  ASSERT_NEAR(47.1239,(**it++).area(),0.001);
  ASSERT_NEAR(12.5,(**it++).area(),0.001);
  ASSERT_NEAR(0.872665,(**it).area(),0.001);



}

TEST(SortTest, sortAreaByLamdaInAscending)
{
  std::cout << "SortArea2()"<<endl;
  Shape* shape_array[] = {new CircularSector(10,60),new Triangle(0,0,5,0,5,5),new Ellipse(10,5)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
    shapeVec->push_back(shape_array[i]);
  Sort sort(shapeVec);

  sort.sortArea([](Shape* a,Shape* b){
    return a->area() < b->area();
  });
  std::vector<Shape*>::iterator it;

  for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
    std::cout << ' ' << (**it).area();
  std::cout << '\n';

  it=shapeVec->begin();
  ASSERT_NEAR(12.5,(**it++).area(),0.001);
  ASSERT_NEAR(52.3599,(**it++).area(),0.001);
  ASSERT_NEAR(157.08,(**it).area(),0.001);

}

class AreaAscendingByObject{
public:
  bool operator()(Shape* a,Shape* b){
    return a->area() < b->area();
  }
};

TEST(SortTest, sortAreaByObjectInAscending)
{
  std::cout << "SortArea3()"<<endl;
  Shape* shape_array[] = {new CircularSector(10,60),new Triangle(0,0,5,0,5,5),new Ellipse(10,5)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
    shapeVec->push_back(shape_array[i]);
  Sort sort(shapeVec);
  AscendingComparison areaAscendingByObject("area");
  // function<bool(Shape* a,Shape* b)> fuc=ascendingByObject;

  sort.sortArea(areaAscendingByObject);
  std::vector<Shape*>::iterator it;

  for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
    std::cout << ' ' << (**it).area();
  std::cout << '\n';
  it=shapeVec->begin();
  ASSERT_NEAR(12.5,(**it++).area(),0.001);
  ASSERT_NEAR(52.3599,(**it++).area(),0.001);
  ASSERT_NEAR(157.08,(**it).area(),0.001);

  DescendingComparison areaDescendingByObject("area");
  sort.sortArea(areaDescendingByObject);
  for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
    std::cout << ' ' << (**it).area();
  std::cout << '\n';
  it=shapeVec->begin();
  ASSERT_NEAR(157.08,(**it++).area(),0.001);
  ASSERT_NEAR(52.3599,(**it++).area(),0.001);
  ASSERT_NEAR(12.5,(**it).area(),0.001);


}

bool perimeterAscending(Shape* a,Shape* b){
  return a->perimeter() < b->perimeter();
}
TEST(SortTest, sortPerimeterByFunctionInAscending)
{
  std::cout << "SortPerimeter1()"<<endl;
  Shape* shape_array[] = {new Triangle(0,0,5,0,5,5),new CircularSector(5,4),new Ellipse(5,3)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
    shapeVec->push_back(shape_array[i]);

  Sort sort(shapeVec);
  //
  function<bool(Shape* a,Shape* b)> fuc=perimeterAscending;
  sort.sortPerimeter(fuc);


  std::vector<Shape*>::iterator it;
  for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
    std::cout << ' ' << (**it).perimeter();
  std::cout << '\n';
  it=shapeVec->begin();
  ASSERT_NEAR(10.3491,(**it++).perimeter(),0.001);
  ASSERT_NEAR(17.0711,(**it++).perimeter(),0.001);
  ASSERT_NEAR(26.8496,(**it).perimeter(),0.001);

}

TEST(SortTest, sortPerimeterByLambdaInAscending)
{
  std::cout << "SortPerimeter2()"<<endl;
  Shape* shape_array[] = {new Triangle(0,0,5,0,5,5),new CircularSector(5,4),new Ellipse(5,3)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
    shapeVec->push_back(shape_array[i]);

  Sort sort(shapeVec);
  //
  function<bool(Shape* a,Shape* b)> fuc=[](Shape* a,Shape* b){
    return a->perimeter() < b->perimeter();
  };
  sort.sortPerimeter(fuc);


  std::vector<Shape*>::iterator it;
  for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
    std::cout << ' ' << (**it).perimeter();
  std::cout << '\n';
  it=shapeVec->begin();
  ASSERT_NEAR(10.3491,(**it++).perimeter(),0.001);
  ASSERT_NEAR(17.0711,(**it++).perimeter(),0.001);
  ASSERT_NEAR(26.8496,(**it).perimeter(),0.001);

}
class PerimeterAscendinByClass{
public:
  bool operator()(Shape* a,Shape* b){
    return a->perimeter() < b->perimeter();
  }
};

TEST(SortTest, sortPerimeterByObjectInAscending)
{
  std::cout << "SortPerimeter3()"<<endl;
  Shape* shape_array[] = {new Triangle(0,0,5,0,5,5),new CircularSector(5,4),new Ellipse(5,3)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
    shapeVec->push_back(shape_array[i]);

  Sort sort(shapeVec);
  AscendingComparison perimeterAscendingByObject("perimeter");
  function<bool(Shape* a,Shape* b)> fuc=perimeterAscendingByObject;
  sort.sortPerimeter(fuc);


  std::vector<Shape*>::iterator it;
  for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
    std::cout << ' ' << (**it).perimeter();
  std::cout << '\n';
  it=shapeVec->begin();
  ASSERT_NEAR(10.3491,(**it++).perimeter(),0.001);
  ASSERT_NEAR(17.0711,(**it++).perimeter(),0.001);
  ASSERT_NEAR(26.8496,(**it).perimeter(),0.001);

  DescendingComparison perimeterDescendingByObject("perimeter");
  fuc=perimeterDescendingByObject;
  sort.sortPerimeter(fuc);

  for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
    std::cout << ' ' << (**it).perimeter();
  std::cout << '\n';
  it=shapeVec->begin();
  ASSERT_NEAR(26.8496,(**it++).perimeter(),0.001);
  ASSERT_NEAR(17.0711,(**it++).perimeter(),0.001);
  ASSERT_NEAR(10.3491,(**it).perimeter(),0.001);




}


bool sumOfSquaresAscending(Shape* a,Shape* b){
  return a->sumOfSquares() < b->sumOfSquares();
}
TEST(SortTest, sortSumOfSquaresAscendingByFunctionInAscending)
{
  std::cout << "SortSumOfSquares1()"<<endl;
  Shape* shape_array[] = {new Triangle(0,0,5,0,5,5),new CircularSector(5,4),new Ellipse(5,3)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
    shapeVec->push_back(shape_array[i]);

  Sort sort(shapeVec);
  //
  function<bool(Shape* a,Shape* b)> fuc=sumOfSquaresAscending;
  sort.sortSumOfSquares(fuc);


  std::vector<Shape*>::iterator it;
  for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
    std::cout << ' ' << (**it).sumOfSquares();
  std::cout << '\n';
  it=shapeVec->begin();
  ASSERT_NEAR(107.865,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(447.672,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(2941.56,(**it).sumOfSquares(),0.001);

}


TEST(SortTest, sortSumOfSquaresAscendingByLambdaInAscending)
{
  std::cout << "SortSumOfSquares2()";
  Shape* shape_array[] = {new Triangle(0,0,5,0,5,5),new CircularSector(5,4),new Ellipse(5,3)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
    shapeVec->push_back(shape_array[i]);

  Sort sort(shapeVec);
  //
  function<bool(Shape* a,Shape* b)> fuc=[](Shape* a,Shape* b){
    return a->sumOfSquares() < b->sumOfSquares();
  };
  sort.sortSumOfSquares(fuc);


  std::vector<Shape*>::iterator it;
  for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
    std::cout << ' ' << (**it).sumOfSquares();
  std::cout << '\n';
  it=shapeVec->begin();
  ASSERT_NEAR(107.865,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(447.672,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(2941.56,(**it).sumOfSquares(),0.001);

}

TEST(SortTest, sortSumOfSquaresAscendingByClassInAscending)
{
  std::cout << "SortSumOfSquares3()"<<endl;
  Shape* shape_array[] = {new Triangle(0,0,5,0,5,5),new CircularSector(5,4),new Ellipse(5,3)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
    shapeVec->push_back(shape_array[i]);

  Sort sort(shapeVec);
  AscendingComparison SumOfSquaresAscendingByObject("sumOfSquares");
  function<bool(Shape* a,Shape* b)> fuc=SumOfSquaresAscendingByObject;
  sort.sortSumOfSquares(fuc);


  std::vector<Shape*>::iterator it;
  for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
    std::cout << ' ' << (**it).sumOfSquares();
  std::cout << '\n';
  it=shapeVec->begin();
  ASSERT_NEAR(107.865,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(447.672,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(2941.56,(**it).sumOfSquares(),0.001);

  DescendingComparison SumOfSquaresDescendingByObject("sumOfSquares");
  fuc=SumOfSquaresDescendingByObject;
  sort.sortSumOfSquares(fuc);

  for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
    std::cout << ' ' << (**it).sumOfSquares();
  std::cout << '\n';
  it=shapeVec->begin();
  ASSERT_NEAR(2941.56,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(447.672,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(107.865,(**it).sumOfSquares(),0.001);


}
