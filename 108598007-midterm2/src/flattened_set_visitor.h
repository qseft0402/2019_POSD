#ifndef FLATTENED_SET_VISITOR_H
#define FLATTENED_SET_VISITOR_H

#include "visitor.h"
#include "integer.h"
class Set;
class FlattenedSetVisitor:public Visitor{
    public:
    FlattenedSetVisitor();
    void visitInteger(Integer* i);
    void visitSet(Set* s);
    Element* getResult();


    private:
        Set* _matchSet;
        Integer* _integer;
};



#endif