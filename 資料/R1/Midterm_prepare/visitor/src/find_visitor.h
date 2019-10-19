#ifndef FIND_VISITOR_H
#define FIND_VISITOR_H
#include "visitor.h"
#include <string>
#include <algorithm>
using namespace std;

class FindVisitor: public Visitor{
  public:
    FindVisitor();

    void visitFile(File *file);

    void visitFolder(Folder *folder);

    string find(string target);
  private:
    vector<string> _nodeName;
    vector<string> _nodePath;
    string rootPath;
};

#endif
