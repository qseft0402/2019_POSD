#include <gtest/gtest.h>
#include "../src/triangle.h"
#include "../src/circular_sector.h"
#include "../src/ellipse.h"
#include "../src/sort.h"
#include <stdexcept>
// #include "../src/ellipse.h"
#include <algorithm>

TEST (ShapeTest, first)
{
  ASSERT_TRUE(true);
}

TEST(SortTest, AreaAscendingFunction)
{
  std::cout << "AreaAscendingFunction()"<<endl;
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
}


TEST(SortTest, AreaAscendingLambda)
{
  std::cout << "AreaAscendingLambda()"<<endl;
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

TEST(SortTest, AreaAscendingClass)
{
  std::cout << "AreaAscendingClass()"<<endl;
  Shape* shape_array[] = {new CircularSector(10,60),new Triangle(0,0,5,0,5,5),new Ellipse(10,5)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
    shapeVec->push_back(shape_array[i]);
  Sort sort(shapeVec);
  AscendingComparison AreaAscendingClass("area");
  // function<bool(Shape* a,Shape* b)> fuc=ascendingByObject;

  sort.sortArea(AreaAscendingClass);
  std::vector<Shape*>::iterator it;

  for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
    std::cout << ' ' << (**it).area();
  std::cout << '\n';
  it=shapeVec->begin();
  ASSERT_NEAR(12.5,(**it++).area(),0.001);
  ASSERT_NEAR(52.3599,(**it++).area(),0.001);
  ASSERT_NEAR(157.08,(**it).area(),0.001);
}

TEST(SortTest, AreaDescendingClass)
{
  std::cout << "AreaDescendingClass()"<<endl;
  Shape* shape_array[] = {new CircularSector(10,60),new Triangle(0,0,5,0,5,5),new Ellipse(10,5)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
    shapeVec->push_back(shape_array[i]);
  Sort sort(shapeVec);

  DescendingComparison areaDescendingByObject("area");
  sort.sortArea(areaDescendingByObject);
std::vector<Shape*>::iterator it;
  for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
    std::cout << ' ' << (**it).area();
  std::cout << '\n';
  it=shapeVec->begin();
  ASSERT_NEAR(157.08,(**it++).area(),0.001);
  ASSERT_NEAR(52.3599,(**it++).area(),0.001);
  ASSERT_NEAR(12.5,(**it).area(),0.001);
}

TEST(SortTest, AreaDecendingFunction)
{
  std::cout << "AreaDecendingFunction()"<<endl;
  Shape* shape_array[] = {new CircularSector(5,4),new Triangle(0,0,5,0,5,5),new Ellipse(5,3)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
    shapeVec->push_back(shape_array[i]);

  Sort sort(shapeVec);

  function<bool(Shape* a,Shape* b)> fuc=areaDescendingComparison;
  sort.sortArea(fuc);
  std::vector<Shape*>::iterator it;
 for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
   std::cout << ' ' << (**it).area();
  std::cout << '\n';
  it=shapeVec->begin();
  ASSERT_NEAR(47.1239,(**it++).area(),0.001);
  ASSERT_NEAR(12.5,(**it++).area(),0.001);
  ASSERT_NEAR(0.872665,(**it).area(),0.001);
}

TEST(SortTest, AreaDecendingLambda)
{
  std::cout << "AreaDecendingLambda()"<<endl;
  Shape* shape_array[] = {new CircularSector(10,60),new Triangle(0,0,5,0,5,5),new Ellipse(10,5)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
    shapeVec->push_back(shape_array[i]);
  Sort sort(shapeVec);

  sort.sortArea([](Shape* a,Shape* b){
    return a->area() > b->area();
  });
  std::vector<Shape*>::iterator it;

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
TEST(SortTest, perimeterAscendingFunction)
{
  std::cout << "perimeterAscendingFunction()"<<endl;
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

bool perimeterDecending(Shape* a,Shape* b){
  return a->perimeter() > b->perimeter();
}
TEST(SortTest, perimeterDecendingFunction)
{
  std::cout << "perimeterDecendingFunction()"<<endl;
  Shape* shape_array[] = {new Triangle(0,0,5,0,5,5),new CircularSector(5,4),new Ellipse(5,3)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
    shapeVec->push_back(shape_array[i]);

  Sort sort(shapeVec);
  //
  function<bool(Shape* a,Shape* b)> fuc=perimeterDecending;
  sort.sortPerimeter(fuc);


  std::vector<Shape*>::iterator it;
  for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
    std::cout << ' ' << (**it).perimeter();
  std::cout << '\n';
  it=shapeVec->begin();
  ASSERT_NEAR(26.8496,(**it++).perimeter(),0.001);
  ASSERT_NEAR(17.0711,(**it++).perimeter(),0.001);
  ASSERT_NEAR(10.3491,(**it).perimeter(),0.001);

}

TEST(SortTest, perimeterAscendingLambda)
{
  std::cout << "perimeterAscendingLambda()"<<endl;
  Shape* shape_array[] = {new Triangle(0,0,5,0,5,5),new CircularSector(5,4),new Ellipse(5,3)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
    shapeVec->push_back(shape_array[i]);

  Sort sort(shapeVec);
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

TEST(SortTest, perimeterDecendingLambda)
{
  std::cout << "perimeterDecendingLambda()"<<endl;
  Shape* shape_array[] = {new Triangle(0,0,5,0,5,5),new CircularSector(5,4),new Ellipse(5,3)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
    shapeVec->push_back(shape_array[i]);

  Sort sort(shapeVec);
  function<bool(Shape* a,Shape* b)> fuc=[](Shape* a,Shape* b){
    return a->perimeter() > b->perimeter();
  };
  sort.sortPerimeter(fuc);


  std::vector<Shape*>::iterator it;
  for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
    std::cout << ' ' << (**it).perimeter();
  std::cout << '\n';
  it=shapeVec->begin();
  ASSERT_NEAR(26.8496,(**it++).perimeter(),0.001);
  ASSERT_NEAR(17.0711,(**it++).perimeter(),0.001);
  ASSERT_NEAR(10.3491,(**it).perimeter(),0.001);
}


TEST(SortTest, PerimeterAscendinClass)
{
  std::cout << "PerimeterAscendinClass()"<<endl;
  Shape* shape_array[] = {new Triangle(0,0,5,0,5,5),new CircularSector(5,4),new Ellipse(5,3)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
    shapeVec->push_back(shape_array[i]);

  Sort sort(shapeVec);
  AscendingComparison ascendingComparison("perimeter");
  function<bool(Shape* a,Shape* b)> fuc=ascendingComparison;
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

TEST(SortTest, PerimeterDecendinClass)
{
  std::cout << "PerimeterDecendinClass()"<<endl;
  Shape* shape_array[] = {new Triangle(0,0,5,0,5,5),new CircularSector(5,4),new Ellipse(5,3)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
    shapeVec->push_back(shape_array[i]);
  Sort sort(shapeVec);
  DescendingComparison perimeterDescendingByObject("perimeter");
  function<bool(Shape* a,Shape* b)>  fuc=perimeterDescendingByObject;
  sort.sortPerimeter(fuc);
  std::vector<Shape*>::iterator it;
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
TEST(SortTest, SumOfSquaresAscendingFunction)
{
  std::cout << "SumOfSquaresAscendingFunction()"<<endl;
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


TEST(SortTest, SumOfSquaresAscendingLambda)
{
  std::cout << "SumOfSquaresAscendingLambda()";
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

TEST(SortTest, SumOfSquaresDecendingLambda)
{
  std::cout << "SumOfSquaresDecendingLambda()";
  Shape* shape_array[] = {new Triangle(0,0,5,0,5,5),new CircularSector(5,4),new Ellipse(5,3)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
    shapeVec->push_back(shape_array[i]);

  Sort sort(shapeVec);
  //
  function<bool(Shape* a,Shape* b)> fuc=[](Shape* a,Shape* b){
    return a->sumOfSquares() > b->sumOfSquares();
  };
  sort.sortSumOfSquares(fuc);


  std::vector<Shape*>::iterator it;
  for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
    std::cout << ' ' << (**it).sumOfSquares();
  std::cout << '\n';
  it=shapeVec->begin();
  ASSERT_NEAR(2941.56,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(447.672,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(107.865,(**it).sumOfSquares(),0.001);
}

TEST(SortTest, SumOfSquaresAscendingClass)
{
  std::cout << "SumOfSquaresAscendingClass()"<<endl;
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
}


TEST(SortTest, SumOfSquaresDecendingClass)
{
  std::cout << "SumOfSquaresDecendingClass()"<<endl;
  Shape* shape_array[] = {new Triangle(0,0,5,0,5,5),new CircularSector(5,4),new Ellipse(5,3)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<3;i++)
    shapeVec->push_back(shape_array[i]);

  Sort sort(shapeVec);

  DescendingComparison SumOfSquaresDescendingByObject("sumOfSquares");
  function<bool(Shape* a,Shape* b)> fuc=SumOfSquaresDescendingByObject;
  sort.sortSumOfSquares(fuc);
  std::vector<Shape*>::iterator it;
  for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
    std::cout << ' ' << (**it).sumOfSquares();
  std::cout << '\n';
  it=shapeVec->begin();
  ASSERT_NEAR(2941.56,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(447.672,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(107.865,(**it).sumOfSquares(),0.001);
}

TEST(SortTest, quickSortClass)
{
  std::cout << "quickSortClass()"<<endl;
  Shape* shape_array[] = {new Triangle(0,0,5,0,5,5),new Ellipse(6,4),new CircularSector(6,5),new CircularSector(5,4),new Ellipse(5,3)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<5;i++)
    shapeVec->push_back(shape_array[i]);

  Sort sort(shapeVec);
  AscendingComparison areaAscendingByObject("area");
  function<bool(Shape* a,Shape* b)> fuc=areaAscendingByObject;


  sort.quickSort(fuc);
  std::vector<Shape*>::iterator it;
  for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
    std::cout << ' ' << (**it).area();
  std::cout << '\n';
  it=shapeVec->begin();

  ASSERT_NEAR(0.872665,(**it++).area(),0.001);
  ASSERT_NEAR(1.5708,(**it++).area(),0.001);
  ASSERT_NEAR(12.5,(**it++).area(),0.001);
  ASSERT_NEAR(47.1239,(**it++).area(),0.001);
  ASSERT_NEAR(75.3982,(**it).area(),0.001);
}

TEST(SortTest, quickSortSumOfSquaresClass)
{
  std::cout << "quickSortSumOfSquaresClass()"<<endl;
  Shape* shape_array[] = {new Triangle(0,0,5,0,5,5),new Ellipse(6,4),new CircularSector(6,5),new CircularSector(5,4),new Ellipse(5,3)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<5;i++)
    shapeVec->push_back(shape_array[i]);

  Sort sort(shapeVec);
  AscendingComparison SumOfSquaresAscendingByObject("sumOfSquares");
  function<bool(Shape* a,Shape* b)> fuc=SumOfSquaresAscendingByObject;


  sort.quickSort(fuc);
  std::vector<Shape*>::iterator it;
  for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
    std::cout << ' ' << (**it).sumOfSquares();
  std::cout << '\n';
  it=shapeVec->begin();

  ASSERT_NEAR(107.865,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(159.308,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(447.671,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(2941.56,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(6782.67,(**it).sumOfSquares(),0.001);
}

TEST(SortTest, quickSortFunction)
{
  std::cout << "quickSortFunction()"<<endl;
  Shape* shape_array[] = {new Triangle(0,0,5,0,5,5),new Ellipse(6,4),new CircularSector(6,5),new CircularSector(5,4),new Ellipse(5,3)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<5;i++)
    shapeVec->push_back(shape_array[i]);

  Sort sort(shapeVec);

  function<bool(Shape* a,Shape* b)> fuc=areaAscendingComparison;


  sort.quickSort(fuc);
  std::vector<Shape*>::iterator it;
  for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
    std::cout << ' ' << (**it).sumOfSquares();
  std::cout << '\n';
  it=shapeVec->begin();

  ASSERT_NEAR(107.865,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(159.308,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(447.671,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(2941.56,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(6782.67,(**it).sumOfSquares(),0.001);
}

TEST(SortTest, quickSortLambda)
{
  std::cout << "quickSortLambda()"<<endl;
  Shape* shape_array[] = {new Triangle(0,0,5,0,5,5),new Ellipse(6,4),new CircularSector(6,5),new CircularSector(5,4),new Ellipse(5,3)};
  std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
  shapeVec->clear();
  for(int i=0;i<5;i++)
    shapeVec->push_back(shape_array[i]);

  Sort sort(shapeVec);

  sort.quickSort([](Shape* a,Shape* b){
    return a->sumOfSquares() >b->sumOfSquares();
  });
  std::vector<Shape*>::iterator it;
  for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
    std::cout << ' ' << (**it).sumOfSquares();
  std::cout << '\n';
  it=shapeVec->begin();

  ASSERT_NEAR(6782.67 ,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(2941.56 ,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(447.671 ,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(159.308,(**it++).sumOfSquares(),0.001);
  ASSERT_NEAR(107.865,(**it).sumOfSquares(),0.001);
}
