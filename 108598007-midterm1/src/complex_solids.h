#ifndef COMPLEX_SOLIDS_H
#define COMPLEX_SOLIDS_H
#include "solid.h"
using namespace std;
class ComplexSolids:public Solid
{
  public:
    ComplexSolids(std::vector<Solid*>* solids):_solids(solids){

    }
  void add(Solid* s){
    _solids->push_back(s);
  }
  double bottomArea()const{
    vector<Solid*>::iterator it;
    double sum=0;
    for(it=_solids->begin();it!=_solids->end();it++){
      sum+=(*it)->bottomArea();
    }

    return sum;

  }
  double volume()const{
    vector<Solid*>::iterator it;
    double sum=0;
    for(it=_solids->begin();it!=_solids->end();it++){
      sum+=(*it)->volume();
    }

    return sum;
  }

  int numberOfChild(){
    return this->_solids->size();
  }
  // std::vector<Solid*> find(double volumeMin,double volumeMax,double bottomAreaMin,double bottomAreaMax){
  //
  // };

  private:
    vector<Solid*>* _solids;
};
#endif
