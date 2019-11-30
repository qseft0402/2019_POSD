#ifndef NULL_ITERATOR_H
#define NULL_ITERATOR_H

#include "iterator.h"
class Element;
class NullIterator:public Iterator
{
  public:
    NullIterator(){}
    void first(){
      throw string("No child member!");
    }
    Element* currentItem(){
      throw string("No child member!");
    }
    void next() {
      throw string("No child member!");

    }
    bool isDone(){
      return true;
    }
};
#endif