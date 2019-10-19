#ifndef FILE_H
#define FILE_H

#include "node.h"
#include "null_iterator.h"
#include <map>

class File: public Node{
    public:
      class NullIterator:public NodeIterator{
        public:
          NullIterator(Node *file)
          {

          }
          void first()
          {
            return;
          }
          Node* currentItem()
          {
            return nullptr;
          }
          void next()
          {
          }
          bool isDone()
          {
            return true;
          }
        private:
          map<string, Node *>::iterator _it;
      };

      File(const char * path): Node(path)
      {
        if (!S_ISREG(this->_st.st_mode))
        {
            throw std::string("Path of constructor does not correspond with class.");
        }
      }

    void accept(NodeVisitor *NodeVisitor)
    {
      NodeVisitor->visitFile(this);
    }
    NodeIterator * createIterator()
    {
      return new NullIterator(this);
    }
};
#endif
