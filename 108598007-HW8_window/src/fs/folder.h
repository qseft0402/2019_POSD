#ifndef FOLDER_H
#define FOLDER_H
#include <string>
#include <sys/stat.h>
#include <vector>
#include "visitor.h"
#include "node.h"

class Folder: public Node {
public:
  class FolderIterator : public Iterator
 {
  public:
    FolderIterator(Folder * f):_f(f){
      _map=f->getNodeMap();
    }
    void first()
    {
      it=_map.begin();
      // initialization
    }
    Node* currentItem()
    {
      if(it==_map.end())
        throw string("No current item!");
      else
        return it->second;
      // if iterator is to the end that it should throw string "No current item!"
      // if iterator is not to the end that it should return current node
    }
    void next()
    {
      if(it==_map.end())
        throw string("Moving past the end!");
      it++;
      // if iterator is to the end that it should throw string "Moving past the end!"
      // if iterator is not to the end that it should add 1
    }
    bool isDone()
    {
      return it==_map.end();
      // return iterator is to the end or not?
    }
  private:
    map<string,Node*>::iterator it;
    map<string,Node*> _map;
    Folder* _f;
};

public:
  Folder(std::string path): Node(path) {

    if(!isDir(path.c_str())){
      throw string("It is not Folder!");
    }
  }
  ~Folder(){
    // delete _map;
  }
  void addChild(Node* child) {
    _map.insert({child->name(),child});
  }

  Node* getChild(string name) {
    return _map[name];
  }
  int getChildSize(){
    return _map.size();
  }

  std::string listNode()
  {
    string list="";
    // sort(_map.begin()->second,_map.end()->second,[](Node* a,Node* b){
    //   return a->name() < b->name();
    // });
    for(map<string,Node*>::iterator it=_map.begin();it!=_map.end();it++){
      Node* temp=it->second;
      list+=temp->name();
      // if(it==(_map.end()-1)) break;
        list+=" ";
    }
    list.erase(list.size()-1,1);
    return list;
  }

  string findNode(std::string name){
    vector<Node*> allNode;
    scanAllNode(getNodeMap(),allNode,name);
    vector<string> nameVec;
    regex patten_parent(Node::name());
    regex patten_findName(name);
    std::smatch m;
    for(Node* node: allNode){
      string path=node->getPath();
      // if(node->name()==name)
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

  void scanAllNode(map<string,Node*> myMap,vector<Node*> &allNode,string name){// v放入該資料夾要進行檢查之Vector , 把所有node放入 allNode
   for(map<string,Node*>::iterator it=myMap.begin();it!=myMap.end();it++){
      Node* node=it->second;
      if(node->name()==name)
        allNode.push_back(node);
      if(node->getType()!=1) scanAllNode(node->getNodeMap(),allNode,name);
    }
  }
  std::map<string,Node*> getNodeMap(){//回傳該資料夾之Map
    return _map;
  }
  Iterator* createIterator(){
    return new FolderIterator(this);
  }
  void accept(Visitor * visitor) {
    visitor->visitFolder(this);
    // visitor->reSetMatchNode();
  }
int getChildrenSize(){
  return _map.size();
}
private:
  std::map<string,Node*> _map;
};



#endif
