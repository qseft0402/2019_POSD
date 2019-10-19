#ifndef FILE_H
#define FILE_H
#include "node.h"

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
};
#endif
