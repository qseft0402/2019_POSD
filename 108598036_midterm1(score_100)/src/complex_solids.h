#ifndef COMPLEX_SOLIDS_H
#define COMPLEX_SOLIDS_H
#include "solid.h"
#include <vector>
using namespace std;
class ComplexSolids : public Solid
{
public:
    ComplexSolids(vector<Solid*> * solids): _s(solids){

    }
    void add(Solid *s){
      _s->push_back(s);
    }
    double bottomArea() const{
      double sum=0.0;
      for(vector<Solid*>::iterator it = _s->begin();it != _s->end();++it) {
        sum+= (*it)->bottomArea();
      }
      return sum;
    }
    double volume() const{
      double sum=0.0;
      for(vector<Solid*>::iterator it = _s->begin();it != _s->end();++it) {
        sum+= (*it)->volume();
      }
      return sum;
    }
    int numberOfChild(){
      return _s->size();
    }
    bool isComplexSolids(){
      return true;
    }

    vector<Solid*> find(double volumeMin,double volumeMax,double bottomAreaMin,double bottomAreaMax){
      vector<Solid*> get,tmp;
      for(vector<Solid*>::iterator it = _s->begin();it != _s->end();++it) {
        if((*it)->isComplexSolids()&&(*it)->numberOfChild() != 0){
          tmp = (*it)->find(volumeMin,volumeMax,bottomAreaMin,bottomAreaMax);
          for(vector<Solid*>::iterator it = tmp.begin();it != tmp.end();++it){
            get.push_back(*it);
          }
        }else{
          tmp = (*it)->find(volumeMin,volumeMax,bottomAreaMin,bottomAreaMax);
          if(tmp.size() != 0)
            get.push_back(tmp.at(0));
        }
      }
      return get;
    }

  private:
    vector<Solid*> * _s;
};
#endif
