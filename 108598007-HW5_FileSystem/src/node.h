#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;
#include <regex>
#include <sys/stat.h>
#include <fstream>
#include <dirent.h>
#include <string>
#include "iterator.h"
class Node{

public:
  Node(string path): _path(path) {
    if(isExists(path)){
    }else{
      throw string("Node is not exist!");
    }
    if(isFile(path.c_str()))this->_type=1;
    else this->_type=2;
    stat(_path.c_str(), &_st);
    // scanDir("./test/");
    this->_name=setName(path);

 }
 virtual ~Node(){}
 std::string name()
  {
        // For example path:"test/TA_folder/hello.txt"
        // "hello.txt" is name
        // Return "hello.txt"
   return this->_name;
  }

  virtual std::string findNode(std::string name)
  {

        throw string("Node can't finde node!");
  }

  virtual std::string listNode()
  {
    throw string("Not a directory");
        // implementation list child Node and Sort by dictionary
        // Result should be separated by space
        // For example:
        // Folder contains childnode "a.out" and "TA_folder" and "hello.txt"
        // It should return "TA_folder a.out hello.txt"
        // If node is file, it can't listNode.
        // It should throw "Not a directory"
        // For Example: TA_file->listNode()
  }
  virtual void addChild(Node* child) {
    throw string("Invalid add!");
  }

  virtual Node* getChild(int num) {
    return nullptr;
  }

  string getPath(){
    return this->_path;
  }
  int getType(){
    return this->_type;
  }
  virtual std::map<string,Node*> getNodeMap(){
    throw string("File no map!");
  }
  virtual Iterator* createIterator()=0;
  inline bool isExists (std::string name) {
      return ( access( name.c_str(), F_OK ) != -1 );
  }
  int getSize(){
    return _st.st_size;
  }

  bool isFile(const char* path) {
      struct stat buf;
      stat(path, &buf);
      return S_ISREG(buf.st_mode);
  }

  bool isDir(const char* path) {
      struct stat buf;
      stat(path, &buf);
      return S_ISDIR(buf.st_mode);
  }
  string setName(string path){
    string name="";
    regex e ("/");
    if(regex_search(path,e))
      return setName(path.erase(0,path.find('/')+1));
    else
      return path;
  }

  int size() {
    return _st.st_size;
  }
  virtual void scanAllNode(vector<Node*> v,vector<Node*> &nameVec,string name){
    throw string("File can't scan all node!");
  }
private:
  string _path;
  string _name;
  int _type;//file:1 folder:2
  struct stat _st;
};

#endif
