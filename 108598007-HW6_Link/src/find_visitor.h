#ifndef FIND_VISITOR_H
#define FIND_VISITOR_H
#include <string>
#include "visitor.h"
#include <vector>
#include "node.h"
class Iterator;
class Link;
class FindVisitor:public Visitor
{
    public:
        class FindVisitorIterator:public Iterator{
            public:
                FindVisitorIterator(FindVisitor* fv):_fv(fv){
                   _map= _fv->_matchNode;
                }
                void first(){
                    it=_map.begin();
                }
                Node* currentItem(){
                    if(it==_map.end())
                        throw string("NO current item!");
                    else
                        return it->second;
                }
                void next(){
                    if(it==_map.end())
                        throw string("Movingg past the end!");
                    it++;
                }
                bool isDone(){
                    return it==_map.end();
                }
                map<string,Node*>::iterator it;
                map<string,Node*> _map;
                FindVisitor* _fv;
        };
    public:
        FindVisitor(string name); // Name is the target we want to find.
        void visitFolder(Folder * folder);
        void visitFile(File * file);
        void visitLink(Link * link); // You only need to check the link itself,and you don't have to check the node that the link point to!  
        string findResult();
        void reSetMatchNode();
        Iterator * createIterator();
    private:
        string _name;
        string _result;
        std::map<string,Node*> _matchNode;;
        string _folderPath;
};
#endif