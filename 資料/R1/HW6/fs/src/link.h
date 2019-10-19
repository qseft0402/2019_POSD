#ifndef LINK_H
#define LINK_H

#include "node.h"

class Link : public Node{
public:
  Link(const char * path, Node * node = nullptr) : Node(path)
  {
    if (!S_ISLNK(this->_st.st_mode))
    {
        throw std::string("Path don't correspond with class.");
    }

    this->addLink(node);
  }

  void accept(NodeVisitor * nodevisitor)
  {
    nodevisitor->visitLink(this);
  }

  void addLink(Node * node)
  {
    _source = node;
  }

  Node * getSource()
  {
    return _source;
  }

  NodeIterator * createIterator()
  {
    return new NullIterator(this);
  }

private:
  Node * _source;
};

#endif
