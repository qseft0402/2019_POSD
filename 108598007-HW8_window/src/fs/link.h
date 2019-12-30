#ifndef LINK_H
#define LINK_H
#include "node.h"
#include "visitor.h"
#include "iterator.h"
#include "null_iterator.h"
class Link :public Node{
public:
  Link(string path,Node* node=nullptr):Node(path){
    
    lstat(path.c_str(),&_st);
    if(!S_ISLNK(this->_st.st_mode)){
      throw string("It is not Link!");
    }
    this->_type=3;
    this->addLink(node);
    //   else if (isExists(path)){throw string("Link is not exist!");}

  } // You should check path if it is not a link that you should throw string "It is not Link!"
  ~Link(){};
  void accept(Visitor* visitor){
      visitor->visitLink(this);
  } // aceep visitor

  void addLink(Node * node){
      this->_node=node;
  } // add symbolic link

  Node * getSource(){
      return this->_node;
  } // return node that the link point to!

  Iterator* createIterator(){
    return new NullIterator();
  } // return null Iterator
  // string name(){
  //   return this->Node::name();
  // }

private:
    Visitor* _visitor;
    Node* _node;
    // struct stat _st;
};


#endif