#ifndef sort_h
#define sort_h

#include <algorithm>    // std::sort
#include <string>
#include <iostream>
using namespace std;

bool perimeterAscendingComparison(Shape *a, Shape *b)
{
    return a->perimeter() < b->perimeter();
}

bool perimeterDescendingComparison(Shape *a, Shape *b)
{
    return a->perimeter() > b->perimeter();
}

class CompactnessAscendingComparison{
  public:
    bool operator() (Shape *i, Shape *j)
  {
    return (i->compactness() < j->compactness());
  }
};


class CompactnessDescendingComparison{
  public:
    bool operator() (Shape *i, Shape *j)
  {
    return (i->compactness() > j->compactness());
  }
};


class Sort{
    public:
      Sort(std::vector<Shape*>* v): _v(v)
      {
      }
      // The argument ** Accept comparison ** can accept lambda, function, and object
      template<typename comparison>
      void sortArea(comparison what)
      {
        std::sort(_v->begin(), _v->end(), what);
      }

      void sortPerimeter(bool (&comparison)(Shape *a, Shape *b))
      {
        std::sort(_v->begin(), _v->end(), comparison);

      }
      template<class cks>
      void sortCompactness(cks cksQQ)
      {
        std::sort(_v->begin(), _v->end(), cksQQ);
      }

    private:
      std::vector<Shape*>* _v;

};
#endif /* sort_h */
