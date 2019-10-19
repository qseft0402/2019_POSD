#ifndef FIND_VISITOR_H
#define FIND_VISITOR_H
#include "node_visitor.h"
#include "node_iterator.h"
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class FindVisitor: public NodeVisitor
{
  public:
    class FindIterator: public NodeIterator
    {
      public:
        FindIterator(FindVisitor * fv):_fv(fv)
        {

        }
        void first()
        {
          _it = _fv->_nodes.begin();
        }

        Node* currentItem()
        {
          if(isDone()){
            throw std::string("no current item");
          }
          return _it->second;
        }

        void next()
        {
          if (isDone())
          {
            throw string("moving past the end");
          }
          if(!isDone())
          {
            _it++;
          }
        }

        bool isDone()
        {
          return _it == _fv->_nodes.end();
        }

      private:
        FindVisitor *_fv;
        map<string, Node *>::iterator _it;
    };

    FindVisitor(string target);

    void visitFile(File *file);
    void visitFolder(Folder *folder);
    void visitLink(Link *link);

    string findResult();

    NodeIterator * createIterator()
    {
      return new FindIterator(this);
    }
  private:
    map<string, Node*>_nodes;
    string _rootPath;
    string _target;
};

#endif
