#ifndef NODE_VISITOR_H
#define NODE_VISITOR_H
#include "node_iterator.h"
#include <vector>
#include <map>
#include <string>

using namespace std;

class File;
class Folder;
class Link;

class NodeVisitor
{
  public:
    NodeVisitor(){}

    virtual void visitFile(File *file) = 0;
    virtual void visitFolder(Folder *folder) = 0;
    virtual void visitLink(Link *link) = 0;
    virtual int getContentSize(){}
    virtual string findResult(){}
    virtual NodeIterator *createIterator() = 0;

  private:
};

#endif
