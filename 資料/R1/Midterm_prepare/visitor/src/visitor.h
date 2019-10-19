#ifndef VISITOR_H
#define VISITOR_H

#include <vector>
#include <string>

using namespace std;

class File;
class Folder;
class Node;

class Visitor{
  public:
    Visitor(){}

    virtual void visitFile(File *file) = 0;
    virtual void visitFolder(Folder *folder) = 0;
    virtual int getContentSize() const{};
    virtual string find(string target){}

  private:
};

#endif
