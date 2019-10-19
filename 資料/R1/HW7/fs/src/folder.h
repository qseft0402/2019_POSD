#ifndef FOLDER_H
#define FOLDER_H

#include <iostream>
#include <stack>
#include <map>
#include <algorithm>
#include <iterator>
#include "node.h"

using namespace std;

class Folder:public Node{
  //friend InfoContentNodeVisitor;
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
        return _it->second;
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
      std::map<string, Node*>::iterator _it;
    };

    Folder(const char* path):Node(path)
    {
      if (!S_ISDIR(this->_st.st_mode))
      {
          throw std::string("Path of constructor does not correspond with class.");
      }
    }

    void add(Node *node)
    {
      node->setParent(this);
      _children[node->getPath()] = node;
    }

    /*void remove(Node *node)
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
    }*/

    int numberOfChildren() const
    {
      return _children.size();
    }

    void accept(NodeVisitor *NodeVisitor)
    {
      NodeVisitor->visitFolder(this);
    }

    NodeIterator * createIterator()
    {
      return new FolderIterator(this);
    }

  private:
    map<string, Node *> _children;
  };

#endif
