#include <gtest/gtest.h>
#include "../src/triangle.h"
#include "../src/circular_sector.h"
#include "../src/ellipse.h"
#include "../src/sort.h"
#include "../src/terminal.h"
#include <stdexcept>
// #include "../src/ellipse.h"
#include <algorithm>

// TEST(SortTest, quickSortLambda)
// {
//   std::cout << "quickSortLambda()"<<endl;
//   Shape* shape_array[] = {new Triangle(0,0,5,0,5,5),new Ellipse(6,4),new CircularSector(6,5),new CircularSector(5,4),new Ellipse(5,3)};
//   std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
//   shapeVec->clear();
//   for(int i=0;i<5;i++)
//     shapeVec->push_back(shape_array[i]);
//
//   Sort sort(shapeVec);
//
//   sort.quickSort([](Shape* a,Shape* b){
//     return a->sumOfSquares() >b->sumOfSquares();
//   });
//   std::vector<Shape*>::iterator it;
//   for (it = shapeVec->begin() ; it != shapeVec->end(); ++it)
//     std::cout << ' ' << (**it).sumOfSquares();
//   std::cout << '\n';
//   it=shapeVec->begin();
//
//   ASSERT_NEAR(6782.67 ,(**it++).sumOfSquares(),0.001);
//   ASSERT_NEAR(2941.56 ,(**it++).sumOfSquares(),0.001);
//   ASSERT_NEAR(447.671 ,(**it++).sumOfSquares(),0.001);
//   ASSERT_NEAR(159.308,(**it++).sumOfSquares(),0.001);
//   ASSERT_NEAR(107.865,(**it).sumOfSquares(),0.001);
// }

TEST(TerminalTest, TestShowResult)
{
  Terminal *test;
  try{
  test = new Terminal("Triangle (-2,0,0,3,2,0) Triangle (-2,0,0,6,2,0) area dec");
  }catch(std::string *caught){
    cout<<*caught<<endl;
  }
  ASSERT_EQ("[12.000000, 6.000000]", test->showResult());
}

TEST(TerminalTest, AreaAscending)
{
  Terminal *test;
  try{
  test = new Terminal("Ellipse (6,5) Triangle (3,0,0,2,-3,0) CircularSector (8,40) area inc");
  }catch(std::string *caught){
    cout<<*caught<<endl;
  }
  ASSERT_EQ("[6.000000, 22.340214, 94.247780]", test->showResult());
}

TEST(TerminalTest, InvalidCharacter)
{
  Terminal *test;
  try{
  test = new Terminal("Ellipse (6,5) Triangle!@#$%% (3,0,0,2,-3,0) CircularSector (8,40) area inc");
  }catch(std::string *caught){
    cout<<*caught<<endl;
  }
  ASSERT_EQ("[22.340214, 94.247780]", test->showResult());
}

TEST(TerminalTest, Incompelet)
{
  Terminal *test;
  try{
  test = new Terminal("Ellipse (6,5) Triangle (3,0,0,2,-3,0) CircularSector (8,40) area");
  // test->showResult();
}catch(std::string caught){
    cout<<caught<<endl;
    ASSERT_EQ("Unuseful User Input!",caught);
  }

}

TEST(TerminalTest, SkipSpace)
{
  Terminal *test;
  try{
  test = new Terminal("Ellipse (6  ,   5) Triangle (3  ,0    ,  0  , 2,  -3,0) CircularSector (8  ,  40) area inc");
  }catch(std::string *caught){
    cout<<*caught<<endl;
  }
  ASSERT_EQ("[6.000000, 22.340214, 94.247780]", test->showResult());
}

TEST(TerminalTest, SkipSpecialCharacter)
{
  Terminal *test;
  try{
  test = new Terminal("Ellipse (6,5) Triangle (3,0,0,2,-3,0) CircularSector (8,40) area inc !@#$%%");
  }catch(std::string *caught){
    cout<<*caught<<endl;
  }
  ASSERT_EQ("[6.000000, 22.340214, 94.247780]", test->showResult());
}

TEST(TerminalTest, NoUpcase)
{
  Terminal *test;
  try{
  test = new Terminal("Ellipse (6,5) triangle (3,0,0,2,-3,0) CircularSector (8,40) area inc");
  }catch(std::string *caught){
    cout<<*caught<<endl;
  }
  ASSERT_EQ("[22.340214, 94.247780]", test->showResult());
}

TEST(TerminalTest, SpecialCharacteInShape)
{
  Terminal *test;
  try{
  test = new Terminal("Ellipse (6,5) Triangle!@#$%% (3,0,0,2,-3,0) CircularSector (8,40) area inc");
  }catch(std::string *caught){
    cout<<*caught<<endl;
  }
  ASSERT_EQ("[22.340214, 94.247780]", test->showResult());
}

TEST(TerminalTest, NumberOfArugumentIsWrong)
{
  Terminal *test;
  try{
  test = new Terminal("Ellipse (6,5) Triangle (3,0,0) CircularSector (8,40) area inc");
  }catch(std::string *caught){
    cout<<*caught<<endl;
  }
  ASSERT_EQ("[22.340214, 94.247780]", test->showResult());
}

TEST(TerminalTest, TypeOfArugumentIsWrong)
{
  Terminal *test;
  try{
  test = new Terminal("Ellipse (6,5) Triangle (3,0,0,2,-3,zero) CircularSector (8,40) area inc");
  }catch(std::string *caught){
    cout<<*caught<<endl;
  }
  ASSERT_EQ("[22.340214, 94.247780]", test->showResult());
}
