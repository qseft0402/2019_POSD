#ifndef SORT_H
#define SORT_H
#include <iostream>     // std::cout
using namespace std;
#include <algorithm>    // std::sort
#include <vector>
#include <functional>



class Sort{
    public:
      Sort(std::vector<Shape*>* v): _v(v){}

      void sortArea(function<bool(Shape* a,Shape* b)> fuc){
          std::sort((*_v).begin(),(*_v).end(),fuc);
      }


      void sortPerimeter(function<bool(Shape* a,Shape* b)> fuc){
        std::sort((*_v).begin(),(*_v).end(),fuc);
      }

      void sortSumOfSquares(function<bool(Shape* a,Shape* b)> fuc){
          std::sort((*_v).begin(),(*_v).end(),fuc);
      }


      void quickSort(function<bool(Shape* a,Shape* b)> fuc){
      std::vector<Shape*>::iterator it;
      int count=0;
      int pivot=0;
      for (it = _v->begin() ; it != _v->end(); ++it){
        count++;
      }
      it=_v->begin();
      cout<<fuc((*it),(*(it+1)))<<endl;
      myQuickSort(it,0,count,fuc);

      }
      void myQuickSort(std::vector<Shape*>::iterator it,int front,int end,function<bool(Shape* a,Shape* b)> fuc){
        if(front <end){
          int pivot = Partition(it,front,end,fuc);
          myQuickSort(it,front,pivot,fuc);
          myQuickSort(it,pivot+1,end,fuc);
        }
      }
      int Partition(std::vector<Shape*>::iterator it,int front,int end,function<bool(Shape* a,Shape* b)> fuc){

        it=_v->begin();
        Shape *pivot=*(it+end-1);

        int i=front - 1;
        for(int j=front;j<end;j++){
          if(fuc(*(it+j),pivot)){
            i++;
            swap((*(it+i)),(*(it+j)));
          }
        }
        i++;
        it = _v->begin();
        swap((*(it+i)),(*(it+end-1)));
        return i;

      }
private:
      std::vector<Shape*>* _v;
};

// implement following call back function
bool areaAscendingComparison(Shape *a, Shape *b){
  return a->area() < b->area();
};

bool areaDescendingComparison(Shape *a, Shape *b){
  return a->area() > b->area();
};

class AscendingComparison{
public:
    AscendingComparison(string instruction): _instruction(instruction){

    }
    bool operator()(Shape* a,Shape*b){
      if(_instruction=="area"){
        return a->area() < b->area();
      }
      else if(_instruction=="perimeter"){
        return a->perimeter() < b->perimeter();
      }
      else if(_instruction=="sumOfSquares"){
        return a->sumOfSquares() < b->sumOfSquares();
      }
      else{
        return false;
      }
    }
private:
  string _instruction;
};
//
class DescendingComparison{
public:
    DescendingComparison(string instruction): _instruction(instruction){

    }
    bool operator()(Shape* a,Shape*b){
      if(_instruction=="area"){
        return a->area() > b->area();
      }
      else if(_instruction=="perimeter"){
        return a->perimeter() > b->perimeter();
      }
      else if(_instruction=="sumOfSquares"){
        return a->sumOfSquares() > b->sumOfSquares();
      }
      else{
        cout<<"no any instruction"<<endl;
        return false;
      }
    }
  private:
    string _instruction;
};
#endif
