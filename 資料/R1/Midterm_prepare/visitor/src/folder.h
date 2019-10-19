#ifndef FOLDER_H
#define FOLDER_H

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include "node.h"
#include "visitor.h"
#include "node_iterator.h"
using namespace std;

class Folder:public Node{
  //friend InfoContentVisitor;
  public:
    class FolderIterator : public NodeIterator
    {
    public:
      FolderIterator(Folder * f): _folder(f)
      {

      }
      void first()
      {
        _it = _folder->_children.begin();
      }
      Node* currentItem()
      {
        if (isDone())
        {
          throw std::string("no current item");
        }
        return *_it;
      }
      void next()
      {
        if (isDone())
        {
          throw std::string("moving past the end");
        }
        _it++;
      }
      bool isDone()
      {
        return _it == _folder->_children.end();
      }
    private:
      Folder * _folder;
      std::vector<Node*>::iterator _it;
    };
    Folder(const char* path):Node(path)
    {
    }

    void add(Node *node)
    {
      _children.push_back(node);
    }

    void remove(Node *node)
    {
      int i;
      string nodeName = node->getName();
      for (i = 0; i < _children.size(); i++)
      {
              if(_children[i]->getName() == nodeName)
              {
                _children.erase(_children.begin() + i);
              }
      }
    }

    int numberOfChildren() const
    {
      return _children.size();
    }

    void accept(Visitor *visitor)
    {
      visitor->visitFolder(this);
    }

    NodeIterator * createIterator()
    {
      return new FolderIterator(this);
    }

  private:
    vector<Node *> _children;
  };

#endif
