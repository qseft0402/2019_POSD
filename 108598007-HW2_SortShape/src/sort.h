#ifndef SORT_H
#define SORT_H
#include <iostream>     // std::cout
using namespace std;
#include <algorithm>    // std::sort
#include <vector>
#include <functional>



class Sort{
    public:
      Sort(std::vector<Shape*>* v): _v(v){
        // for(int i=0;i<_v->size();i++)
        //   cout<<(*_v)[i]->sumOfSquares()<<endl;
        // std::cout << "Class contains:";
        // for (std::vector<Shape*>::iterator it = _v->begin() ; it != _v->end(); ++it)
        //   std::cout << ' ' << (**it).area();
        // std::cout << '\n';
      }

      // The argument ** Accept comparison ** can accept lambda, function, and object

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
        // cout << ' ' << (**it).area()<<endl;
        count++;
      }
      // cout<<"count="<<count<<endl;
      it=_v->begin();
      cout<<fuc((*it),(*(it+1)))<<endl;
      myQuickSort(it,0,count,fuc);
      // for (it = _v->begin() ; it != _v->end(); ++it)
      //   std::cout << ' ' << (**it).perimeter();
      // std::cout << '\n';
      // fuc()
      }
      void myQuickSort(std::vector<Shape*>::iterator it,int front,int end,function<bool(Shape* a,Shape* b)> fuc){
        if(front <end){
          int pivot = Partition(it,front,end,fuc);
          myQuickSort(it,front,pivot,fuc);
          myQuickSort(it,pivot+1,end,fuc);
        }
      }
      int Partition(std::vector<Shape*>::iterator it,int front,int end,function<bool(Shape* a,Shape* b)> fuc){
        // cout<<""<<endl;
        // cout<<""<<endl;
        // cout<<"Partition"<<endl;
        it=_v->begin();
        Shape *pivot=*(it+end-1);
        // cout<<"Pivot="<<pivot->area();
        // cout<<pivot->area()<<endl;
        int i=front - 1;
        for(int j=front;j<end;j++){
          if(fuc(*(it+j),pivot)){
            i++;
            // cout<<(*(it+j))->area()<<"  "<<pivot->area()<<endl;
            swap((*(it+i)),(*(it+j)));
          }
        }
        i++;
        it = _v->begin();
        // cout <<"i="<<i<<endl;
        swap((*(it+i)),(*(it+end-1)));
        // for (it = _v->begin() ; it != _v->end(); ++it){
        //   cout << ' ' << (**it).area()<<endl;
        // }
        return i;
        // cout<<(*it)->area()<<"  "<<(*(it+1))->area()<<endl;
        // swap(*it,*(++it));
        // cout<<(*it)->area()<<"  "<<(*(it+1))->area()<<endl;

      }


        // quickSort() function should be function template
        // You should write the quickSort by yourself!
        // In the loop of the quickSort algorithm, use Iterator to control your vector rather than index.
        // ***
        // Example:
        //     for ( std::vector<...>::iterator it ... )
        // ***


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
        // cout<<"area!!"<<endl;
        return a->area() < b->area();
      }
      else if(_instruction=="perimeter"){

        // cout<<"perimeter!!"<<endl;
        return a->perimeter() < b->perimeter();
      }
      else if(_instruction=="sumOfSquares"){
        // cout<<"sumOfSquares!!"<<endl;
        return a->sumOfSquares() < b->sumOfSquares();
      }
      else{
        cout<<"no any instruction"<<endl;
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
        // cout<<"area!!"<<endl;
        return a->area() > b->area();
      }
      else if(_instruction=="perimeter"){

        // cout<<"perimeter!!"<<endl;
        return a->perimeter() > b->perimeter();
      }
      else if(_instruction=="sumOfSquares"){
        // cout<<"sumOfSquares!!"<<endl;
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
