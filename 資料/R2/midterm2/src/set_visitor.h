#ifndef SET_VISITOR_H
#define SET_VISITOR_H

class Set;

class SetVisitor {
    public:
        virtual void visitSet(Set* set) = 0;
};

#endif