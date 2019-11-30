#ifndef INTEGER_H
#define INTEGER_H
using namespace std;
#include <string>
#include "element.h"
#include "iterator.h"
#include "null_iterator.h"
#include "visitor.h"
class Integer:public Element{
    public:
    Integer(int i):_value(i){

    }
    void add(Element* element){
        throw string("It's an integer!");
    }
    int size(){
        return 1;
    }
    string toString(){
        return to_string(_value);
    }
    Iterator* createIterator(){
        return new NullIterator();
    }
    void setOperator(char c ){
        throw string("Cannot set operator on it!");
    }
    void accept(Visitor* visitor){
        visitor->visitInteger(this);
    }
    int getValue(){
        return _value;
    }

    private:
    int _value;
};

#endif
