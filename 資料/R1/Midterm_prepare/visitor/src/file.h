#ifndef FILE_H
#define FILE_H

#include "node.h"
#include "visitor.h"

class File: public Node{
  public:
    File(const char * path): Node(path)
    {

    }

    void accept(Visitor *visitor)
    {
      visitor->visitFile(this);
    }
};
#endif
