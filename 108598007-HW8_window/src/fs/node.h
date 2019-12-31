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
#include "visitor.h"
#include <stdio.h>
#include <unistd.h>
#include <map>
#include "../tree_frame.h"
class Node{

public:
  Node(string path): _path(path),_type(0),_wxTreeItemId(nullptr){
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

  int getSize(){
    return _st.st_size;
  }

  static bool isFile(const char* path) {
        struct stat buf;
        lstat(path, &buf);
        return S_ISREG(buf.st_mode);
  }

  static bool isDir(const char* path) {
      struct stat buf;
      lstat(path, &buf);
      return S_ISDIR(buf.st_mode);
  }
  static bool isLink(const char* path) {
      struct stat buf;
      lstat(path, &buf);
      return S_ISLNK(buf.st_mode);
  }
  inline bool isExists (std::string name) {
      return ( access( name.c_str(), F_OK ) != -1 );
  }



  string setName(string path){
    regex e ("/");
    if(regex_search(path,e))
      return setName(path.erase(0,path.find('/')+1));
    else
      return path;
  }

  // int size() {
  //   return _st.st_size;
  // }
  virtual void scanAllNode(vector<Node*> v,vector<Node*> &nameVec,string name){
    throw string("File can't scan all node!");
  }
  virtual void accept(Visitor* visitor) {
    throw string("Node can't accept");
  }
  void updateParentPath(string parentPath){
    string newPath=parentPath+'/'+name();
    // cout<<_path<<"-->"<<newPath<<endl;

    this->_path=newPath;

  }
  void renameNode(string new_name)
  {

    string newPath=getParentPath()+"/"+new_name;
    // cout<<"renameNode! "<<newPath<<endl;
    int result=rename(_path.c_str(),newPath.c_str());
    // cout<<_path<<"-->"<<newPath<<endl;
    if(result==0){
      _name=new_name;
      _path=newPath;
    }else{
      // cout<<_name<<"-->"<<new_name<<"rename fail"<<endl;

      // throw string("rename fail");
    }

    /* You should update
      1. The physical node name.
      2. The node name in your own file system
    */
  }
  string getParentPath(){
    // cout<<path.length()<<endl;
    string path=getPath();
    for(int i=_path.length()-1;i>=0;i--){
      if(path[i]=='/'){
        path.erase((i),path.length());
        break;
      }
    }
    return path;
  }
  wxTreeItemId getWxTreeItemId(){
    return _wxTreeItemId;
  }
  void setWxTreeItemId(wxTreeItemId id){
    this->_wxTreeItemId=id;
  }
  int getChildSize(){
    return 0;
  }
  void updateSize(){
    lstat(_path.c_str(), &_st);
  }
  virtual void addLink(Node * node){
    throw std::string("not implement.");
  } // add symbolic link

  virtual Node * getSource(){
    throw std::string("not implement.");
  } // return node that the link point to!
  virtual int getChildrenSize(){
    return 0;
  }



protected:
  struct stat _st;
  string _name;
  int _type;//file:1 folder:2 link:3
private:
  string _path;
  wxTreeItemId  _wxTreeItemId;

  

};

#endif
