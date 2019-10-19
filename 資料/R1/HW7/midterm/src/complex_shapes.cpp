#include "complex_shapes.h"

ComplexShapes::ComplexShapes(std::vector<Shape*>*shapes):_shapes1(shapes)
{
}

double ComplexShapes::area() const
{
  double sum =0;
  for(int i =0; i < _shapes1->size(); i++)
  {
    sum += _shapes1->at(i)->area();
    // cout << "1" << endl;
  }
  return sum;
}

double ComplexShapes::perimeter() const
{
  double sum =0;
  for(int i =0; i < _shapes1->size(); i++)
  {

    sum += _shapes1->at(i)->perimeter();
    // cout << "sum " << sum<<endl;
    // cout << _shapes1->at(i)->perimeter() << endl;
  }
  return sum;
}

int ComplexShapes::numberOfChild() const
{
  return _shapes1->size();
}

void ComplexShapes::add(Shape * sss) const
{
  _shapes1->push_back(sss);
  // cout << "654564654" << endl;
}
