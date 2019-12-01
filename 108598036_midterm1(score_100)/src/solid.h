#ifndef SOLID_H
#define SOLID_H
#include <vector>
using namespace std;
class Solid {
    public:
    virtual double bottomArea() const = 0;
    virtual double volume() const = 0;
    virtual vector<Solid*> find(double volumeMin,double volumeMax,double bottomAreaMin,double bottomAreaMax){
      vector<Solid*> v;
      if (this->volume()>=volumeMin&&this->volume()<=volumeMax){
        if (this->bottomArea()>=bottomAreaMin&&this->bottomArea()<=bottomAreaMax)
          v.push_back(this);
      }
      return v;
    };
    virtual bool isComplexSolids()=0;
    virtual int numberOfChild()=0;
};
#endif
