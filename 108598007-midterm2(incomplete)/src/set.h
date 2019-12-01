#ifndef SET_H
#define SET_H
using namespace std;
#include <string>
#include <map>
#include "element.h"
#include "iterator.h"
#include "visitor.h"

class Visitor;
class Set:public Element{
      public:
        class SetIterator:public Iterator{
            public:
                SetIterator(Set* set):_set(set){
                   _map= _set->_map;
                }
                void first(){
                    it=_map.begin();
                }
                Element* currentItem(){
                    if(it==_map.end())
                        throw string("No current item!");
                    else
                        return it->second;
                }
                void next(){
                    if(it==_map.end())
                        throw string("Moving past the end!");
                    it++;
                }
                bool isDone(){
                    return it==_map.end();
                }
                map<string,Element*>::iterator it;
                map<string,Element*> _map;
                Set* _set;
        };
    public:
    Set():_count(0),_ope('+'){

    }
    void add(Element* element){
        string key="num"+to_string(_count++);
        _map[key]=element;
    }
    virtual int size(){
        return _map.size();
    }

    virtual std::string toString(){
        string result="{";
        Iterator* it=this->createIterator();
 
        for(it->first();!it->isDone();it->next()){
            Element* element=it->currentItem();
            Set * set = dynamic_cast<Set *> (element);
            if (set != nullptr) {
                if(set->size()==0){
                    result+= ",{}";
                }else{
                    result+=","+element->toString();
                }
            }else{
                result+=","+element->toString();
            }

                
        }
        result+="}";
        //  cout<<result<<endl;
        if(size()!=0)
            result.erase(1,1);
        // cout<<result<<endl;
        return result;
    }

    virtual Iterator * createIterator(){
        return new Set::SetIterator(this);
    }

    virtual void setOperator(char ope){
        if( !(ope=='+' || ope=='-' || ope=='*' || ope=='/') )
            throw string("Invalid operator!");
        _ope=ope;
        
    }

    virtual void accept(Visitor * visitor){
        visitor->visitSet(this);
    }
    void clear(){
        _map.clear();
    }
    char getOperator(){
        return _ope;
    }
    private:
        map<string,Element*> _map;
        int _count;
        char _ope;
};

#endif