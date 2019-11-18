#ifndef FILE_H
#define FILE_H
#include "node.h"
#include "iterator.h"
#include "null_iterator.h"

class File : public Node{
public:
  File(std::string path): Node(path) {
    if(!isFile(path.c_str())){
      throw string("It is not File!");
    }
  }
  
  string findNode(std::string name)
  {
        return this->name();
  }
  Iterator* createIterator(){
    return new NullIterator();
  }
  void accept(Visitor * visitor) {
    visitor->visitFile(this);
  }
};
#endif
