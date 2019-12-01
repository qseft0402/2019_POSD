#ifndef EVALUATE_VISITOR_CPP
#define EVALUATE_VISITOR_CPP

#include "evaluate_visitor.h"
#include "set.h"
#include "integer.h"
EvaluateVisitor::EvaluateVisitor():_result(0){

}
void EvaluateVisitor::visitInteger(Integer* i){
    _result=((Element*)i)->getValue();
}
void EvaluateVisitor::visitSet(Set* s){
    Iterator* it=s->createIterator();
    for(it->first();!it->isDone();it->next()){
        Element* element=it->currentItem();
        Set * set = dynamic_cast<Set *> (element);
         if (set != nullptr) {

         }
         else{
     
             if(s->getOperator()=='+')
                _result += element->getValue();
            else if(s->getOperator()=='-')
                _result -= element->getValue();
            else if(s->getOperator()=='/'){
                 if(element->getValue()==0){
                    throw string("Divide by zero!");
             }
            }
                
         }
    }



}
double EvaluateVisitor::getResult(){
    return _result;
}



#endif
