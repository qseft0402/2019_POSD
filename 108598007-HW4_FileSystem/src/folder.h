#ifndef FOLDER_H
#define FOLDER_H
#include <string>
#include <sys/stat.h>
#include <vector>

#include "node.h"

class Folder: public Node {
public:
  Folder(std::string path): Node(path) {

    if(!isDir(path.c_str())){
      throw string("It is not Folder!");
    }
  }
protected:
  void addChild(Node* child) {
    _v.push_back(child);
  }

  Node* getChild(int num) {
    return _v[num];
  }
  std::string listNode()
  {
    string list="";
    sort(_v.begin(),_v.end(),[](Node* a,Node* b){
      return a->name() < b->name();
    });
    for(int i = 0; i < _v.size(); i++){
      list+=_v.at(i)->name();
      if(i==_v.size()-1) break;
      list+=" ";
    }
    // list.erase(list.size());
    return list;
  }

  string findNode(std::string name){
    vector<Node*> allNode;
    scanAllNode(getNodeVector(),allNode);
    vector<string> nameVec;
    regex patten_parent(Node::name());
    regex patten_findName(name);
    std::smatch m;
    for(Node* node: allNode){
      string path=node->getPath();
      if(node->name()==name)
      if(regex_search(path,m,patten_parent) &&regex_search(path,patten_findName) ){
         string s = m.suffix().str();
         nameVec.push_back("."+s);
      }
    }
    string answer="";
    for(int i=0;i<nameVec.size();i++){
      answer+=nameVec.at(i);
      if(i==nameVec.size()-1)break;
      answer+="\n";
    }
    return answer;
  }

  void scanAllNode(vector<Node*> v,vector<Node*> &allNode){// v放入該資料夾要進行檢查之Vector , 把所有node放入 allNode
    for(int i=0;i<v.size();i++){
      Node* node=v.at(i);
      if(node->getType()==1){
        allNode.push_back(node);
      }
      else{
        allNode.push_back(node);
        scanAllNode(node->getNodeVector(),allNode);
      }
    }
  }
  std::vector<Node*> getNodeVector(){//回傳該資料夾之Vector
    return _v;
  }

private:
  std::vector<Node*> _v;
};



#endif
