#ifndef INFO_CONTENT_VISITOR_H
#define INFO_CONTENT_VISITOR_H
#include "node_visitor.h"
#include <iterator>
#include <vector>
#include <map>
using namespace std;

class InfoContentVisitor:public NodeVisitor
{
    public:
      InfoContentVisitor();

      void visitFile(File *file);
      void visitFolder(Folder *folder);
      void visitLink(Link *link);
      NodeIterator *createIterator(){}

      int getContentSize() const
      {
        return _size;
      }

    private:
      int _size;
};

#endif
