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
  // cout << "favVector.size " << favVector.size() << endl;
}

void FindAreaVisitor::visit(ComplexShapes *complexShapes)
{
  favVector.clear();
  // cout << "complexShapes->numberOfChild() " << complexShapes->numberOfChild() << endl;
  for(int i =0; i < complexShapes->numberOfChild(); i++)
  {
    if(complexShapes->getChild(i)->numberOfChild())
    {

      // cout << "complexShapes->getChild( @" << i <<  "@)->area()98798798 " << complexShapes->getChild(i)->area() << endl;

      complexShapes->getChild(i)->accept(this);
      if(complexShapes->getChild(i)->area() >= _min && complexShapes->getChild(i)->area() <= _max)
      {
        favVector.push_back(complexShapes->getChild(i));
      }
    }
    else
    {
     if(complexShapes->getChild(i)->area() >= _min && complexShapes->getChild(i)->area() <= _max)
     {
       // cout << "complexShapes->getChild(i)->area() " << complexShapes->getChild(i)->area() << endl;
       favVector.push_back(complexShapes->getChild(i));
     }
    }

  }
}
vector<Shape*> FindAreaVisitor::findResult()
{
  // for(int i =0 ; i < favVector.size(); i++)
  // {
  //   cout << "favVector.getChild().area()321231 " << favVector.at(i)->area() << endl;
  // }
  // cout << "favVector.size()21231 " << favVector.size() << endl;
  return favVector;
}
