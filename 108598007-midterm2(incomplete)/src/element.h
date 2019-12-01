#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>

class Iterator;
class Visitor;
class Element{
public:
    Element(){}

    virtual void add(Element * s) = 0;

    virtual int size()=0;

    virtual std::string toString() = 0;

    virtual Iterator * createIterator() = 0;

    virtual void setOperator(char ope) = 0;

    virtual void accept(Visitor * fsv) = 0;
    virtual int getValue(){}
    virtual void clear(){}
    virtual char getOperator(){}
protected:
    int type;//int 1 , set 2;
};
#endif