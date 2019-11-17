#ifndef UTILLITIES_H
#define UTILLITIES_H
#include "iterator.h"
#include <string>
class Utilities
{
    public:
        string listNode(Node* node)//利用自訂一Iterator進行存取
        {

          Folder * folder = dynamic_cast<Folder *> (node);
          if (folder != nullptr) {
            Iterator *it =folder->createIterator();
            string list="";
            for( it->first();!it->isDone();it->next()){
                Node* temp=it->currentItem();
                list+=temp->name();
                list+=" ";

            }
            list.erase(list.size()-1,1);
            return list;
          }
          else
            throw string("Not a directory");
            // You should use iterator pattern to access node in folder!
            // You can use dynamic_cast if you need
            // If node is file that it should throw string "Not a directory"
            // This function is same as Hw4 listNode()
        }

        string findNode(Node* node, string name)
        {
            Folder * folder = dynamic_cast<Folder *> (node);
            if (folder != nullptr) {
            Iterator* it = node->createIterator();
            vector<Node*> allNode;
            scanAllNode(it,allNode,name);
            vector<string> nameVec;
            regex patten_parent(node->name());
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
            else
            {
                return node->name();
            }

            // You should use iterator pattern to access node in folder!
            // You can use dynamic_cast if you need
            // This function is same as Hw4 findNode()
        }
    private:
        void scanAllNode(Iterator* it,vector<Node*> &allNode,string name){// v放入該資料夾要進行檢查之Vector , 把所有node放入 allNode

        for(it->first();!it->isDone();it->next()){
            Node* node=it->currentItem();
            if(node->name()==name) allNode.push_back(node);
            if(node->getType()!=1) scanAllNode(node->createIterator(),allNode,name);
            }
        }
};


#endif
