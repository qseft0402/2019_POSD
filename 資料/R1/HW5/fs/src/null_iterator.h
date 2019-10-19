#ifndef NULL_ITERATOR
#define NULL_ITERATOR

#include "node_iterator.h"

class NullIterator:public NodeIterator
{
  public:
    void first()
    {
      //definition by yourself
    }
    Node* currentItem()
    {
      return node;
    }
    void next()
    {
      //
    }
    bool isDone()
    {
      return true;
    }
};

#endif
