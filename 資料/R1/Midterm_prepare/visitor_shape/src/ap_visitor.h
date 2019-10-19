#ifndef AP_VISITOR_H
#define AP_VISITOR_H
#include "visitor.h"

using namespace std;

class APVisitor:public Visitor{
    public:
      APVisitor();

      void visitCircle(Circle *circle);
      void visitTriangle(Triangle *triangle);
      void visitRectangle(Rectangle *rectangle);

      double area() const
      {
        return aarea;
      }
      double perimeter() const
      {
        return pperimeter;
      }
      double compactness() const
      {
          if(aarea == 0)
          {
            throw std::string("Division by zero");
          }
          return ccompactness;
      }
  private:
      double aarea;
      double pperimeter;
      double ccompactness;
};

#endif
