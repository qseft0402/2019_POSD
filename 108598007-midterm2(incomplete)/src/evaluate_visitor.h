#ifndef EVALUATE_VISITOR_H
#define EVALUATE_VISITOR_H

#include "visitor.h"
class Integer;
class Set;
class EvaluateVisitor:public Visitor{
    public:
    EvaluateVisitor();
    void visitInteger(Integer* i);
    void visitSet(Set* s);
    double getResult();
    private:
    double _result;
};



#endif