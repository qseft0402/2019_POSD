#ifndef NULL_ITERATOR
#define NULL_ITERATOR

#include "node_iterator.h"

class NullIterator:public NodeIterator
{
  public:
    NullIterator(Node* node): _node(node) {}

    void first()
    {
      //definition by yourself
    }
    Node* currentItem()
    {
      return this->_node;
    }
    void next()
    {
      //
    }
    bool isDone()
    {
      return true;
    }

  private:
      Node* _node;
};

#endif
