#ifndef INFO_CONTENT_VISITOR_H
#define INFO_CONTENT_VISITOR_H
#include "visitor.h"
#include <iterator>
#include <vector>
using namespace std;

class InfoContentVisitor:public Visitor
{
    public:
      InfoContentVisitor();

      void visitFile(File *file);
      void visitFolder(Folder *folder);

      int getContentSize() const
      {
        return _size;
      }

    private:
      int _size;
};

#endif
