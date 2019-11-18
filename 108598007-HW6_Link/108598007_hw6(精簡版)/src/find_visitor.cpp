#include "find_visitor.h"
#include "link.h"
#include "folder.h"
#include "file.h"
#include <vector>
#include "node.h"
#include <regex>
FindVisitor::FindVisitor(string name):_name(name),_folderPath(""),_result(""){
    _matchNode.clear();
}// Name is the target we want to find.


void FindVisitor::visitFolder(Folder * folder){
    
    if(_folderPath.length()==0){
        _folderPath=folder->getPath();
        _matchNode.clear();
    }
    Iterator* it=folder->createIterator();
    for(it->first();!it->isDone();it->next()){
        Node* currentNode=it->currentItem();
        if(currentNode->name()==_name){
            _matchNode.insert({currentNode->getPath(),currentNode});
        }
        if(currentNode->getChildrenSize()>0){
            currentNode->accept(this);
        }
    }

}

void FindVisitor::visitFile(File * file){
    _matchNode.clear();
    if(file->name()==_name)
        _result=file->name();
    else _result="";
}
void FindVisitor::visitLink(Link * link){// You only need to check the link itself,and you don't have to check the node that the link point to!  
    Node* node=link;

    _result=node->name();
}
string FindVisitor::findResult(){
    Iterator* it=this->createIterator();

   int count;
    for(it->first(),count=0;!it->isDone();it->next(),count++){
        Node* node=it->currentItem();
        string nodePath=node->getPath();
        regex patten_parent(_folderPath);
        regex patten_targetName(_name);
        std::smatch m;
        if(regex_search(nodePath,m,patten_parent)){
            _result+="."+m.suffix().str();
            if(count==_matchNode.size()-1)break;
                _result+="\n";
        }
    }
    string stemp=_result;
    _result="";
    this->reSetMatchNode();
    this->_folderPath="";
    return stemp;
}

void FindVisitor::reSetMatchNode(){
    _matchNode.clear();
}
Iterator* FindVisitor::createIterator(){
    return new FindVisitor::FindVisitorIterator(this);
}

