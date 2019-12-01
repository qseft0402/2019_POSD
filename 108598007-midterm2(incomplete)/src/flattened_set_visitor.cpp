#ifndef FLATTENED_SET_VISITOR_CPP
#define FLATTENED_SET_VISITOR_CPP
#include <iostream>
#include "flattened_set_visitor.h"
#include "element.h"
#include "integer.h"
#include "set.h"
FlattenedSetVisitor::FlattenedSetVisitor(){
    _matchSet=new Set();
    _matchSet->clear();
}
void FlattenedSetVisitor::visitInteger(Integer* i){
    _matchSet->clear();
    _integer=i;

}

void FlattenedSetVisitor::visitSet(Set* s){
    Iterator* it=s->createIterator();
    for(it->first();!it->isDone();it->next()){
        Element* element=it->currentItem();
        // cout<<element->toString()<<endl;
        Set * set = dynamic_cast<Set *> (element);
        if (set != nullptr) {
            if(set->size()!=0){
                set->accept(this);
            }
        }else{
             _matchSet->add(element);
        }
    }
}

Element* FlattenedSetVisitor::getResult(){
    if(_matchSet->size()==0)
        return (Element* )_integer;
    else{
        Set* temp=new Set();
        *temp=*_matchSet;
        _matchSet->clear();
        // cout<<temp->toString()<<endl;
        return temp;
    }
       
 }
#endif