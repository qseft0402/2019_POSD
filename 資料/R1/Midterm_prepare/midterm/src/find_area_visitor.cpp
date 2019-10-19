#include "find_area_visitor.h"

#include "shape.h"
#include "circle.h"
#include "ellipse.h"
#include "rectangle.h"
#include "complex_shapes.h"
#include <vector>
#include <math.h>

FindAreaVisitor::FindAreaVisitor(double min, double max):_min(min), _max(max)
{
}

void FindAreaVisitor::visit(Shape *complexShapes)
{
  favVector.clear();
  for(int i =0; i < complexShapes->numberOfChild(); i++)
  {
    if(complexShapes->getChild(i)->numberOfChild())
    {
      FindAreaVisitor *a = new FindAreaVisitor(_min, _max);
      vector<Shape*> asd;
      asd.clear();
      complexShapes->getChild(i)->accept(a);
      asd = a->findResult();
      for(int i =0 ; i < asd.size(); i++)
      {
        favVector.push_back(asd.at(i));
      }
    }
     if(complexShapes->getChild(i)->area() >= _min && complexShapes->getChild(i)->area() <= _max)
     {
       favVector.push_back(complexShapes->getChild(i));
     }
  }
}
vector<Shape*> FindAreaVisitor::findResult()
{
  return favVector;
}
