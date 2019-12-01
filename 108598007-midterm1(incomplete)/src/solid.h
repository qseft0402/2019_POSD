#ifndef SOLID_H
#define SOLID_H
#include "string"
using namespace std;
class Solid
{
public:
 virtual double bottomArea()const = 0;
 virtual double volume()const = 0;
 virtual std::vector<Solid*> find(double volumeMin,double volumeMax,double bottomAreaMin,double bottomAreaMax){
   vector<Solid*> vec;
   vec.clear();

   vec.push_back(this);
   return vec;

 };
 virtual int numberOfChild(){
   throw string("no numberOfchild!");
 };
 virtual void add(Solid *s){
   throw string("no add!");
 }
};
#endif
