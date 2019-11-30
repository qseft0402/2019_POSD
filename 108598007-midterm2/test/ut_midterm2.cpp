
#ifndef UT_MIDTERM2_CPP
#define UT_MIDTERM2_CPP
#include <gtest/gtest.h>
#include "../src/integer.h"
#include "../src/element.h"
#include "../src/iterator.h"
#include "../src/set.h"
#include "../src/flattened_set_visitor.cpp"
#include "../src/evaluate_visitor.cpp"

#include <string>
int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv) ;
  return RUN_ALL_TESTS() ;
}
TEST (midterm2Test, first)
{
  ASSERT_TRUE(true);
}

TEST(midterm2Test,integer){
    Integer integer(1);
    Integer* integer2=new Integer(2);
    ASSERT_EQ("1",integer.toString());

    ASSERT_ANY_THROW(integer.add(integer2));
    ASSERT_ANY_THROW(integer.setOperator('+'));

}


TEST(midterm2Test,set){
    Element* set=new Set();
    Element* i=new Integer(1);
    Element* i2=new Integer(2);
    set->add(i);
    set->add(i2);
    ASSERT_EQ(2,set->size());
    ASSERT_EQ("{1,2}",set->toString());
    try{
        set->setOperator('@');
        ASSERT_TRUE(false);
    }catch (string s){
    ASSERT_EQ("Invalid operator!",s);
        
    }

}

TEST(midterm2Test,MutipleSets){
    Element* set1=new Set();
    Element* set2=new Set();
    Element* set3=new Set();
    Element* set4=new Set();
    Element* set5=new Set();
    
    Element* i1=new Integer(1);
    Element* i2=new Integer(2);
    Element* i3=new Integer(3);
    Element* i4=new Integer(4);
    Element* i5=new Integer(5);
    
    set1->add(i1);
    set2->add(i2);
    set1->add(set2);
    set3->add(i3);
    set3->add(i4);
    set4->add(i5);
    set4->add(set5);
    set3->add(set4);
    set1->add(set3);
    ASSERT_EQ("{1,{2},{3,4,{5,{}}}}",set1->toString());
    
}
TEST(midterm2Test,ReuseflattenedSetVisitor){
    Element* set1=new Set();
    Element* set2=new Set();
    Element* set3=new Set();
    Element* set4=new Set();
    Element* set5=new Set();
    
    Element* i1=new Integer(1);
    Element* i2=new Integer(2);
    Element* i3=new Integer(3);
    Element* i4=new Integer(4);
    Element* i5=new Integer(5);
    
    set1->add(i1);
    set2->add(i2);
    set1->add(set2);
    set3->add(i3);
    set3->add(i4);
    set4->add(i5);
    set4->add(set5);
    set3->add(set4);
    set1->add(set3);
    FlattenedSetVisitor* fsv=new FlattenedSetVisitor();

    // cout<<"set1 accept!!"<<endl;
    set1->accept(fsv);
    Element* result=fsv->getResult();
    ASSERT_EQ("{1,2,3,4,5}",result->toString());

    // cout<<"set2 accept!!"<<endl;
    set2->accept(fsv);
    // cout<<"set2 size!! "<<set2->size()<<endl;
    
    result=fsv->getResult();
    ASSERT_EQ("{2}",result->toString());
    

    
    // cout<<"set3 accept!!"<<endl;
    set3->accept(fsv);
    // cout<<"set3 size!! "<<set2->size()<<endl;
    
    result=fsv->getResult();
    ASSERT_EQ("{3,4,5}",result->toString());
}

TEST(midterm2Test,flattenedIntVisitor){
    Element* i=new Integer(1);
    Element* i2=new Integer(2);
    FlattenedSetVisitor* fsv=new FlattenedSetVisitor();
    i->accept(fsv);
    Element* result=fsv->getResult();
    ASSERT_EQ("1",result->toString());
    i2->accept(fsv);
    result=fsv->getResult();
    ASSERT_EQ("2",result->toString());
    
}

TEST(midterm2Test,nullIterator){
    Element* i1=new Integer(1);
    Iterator* it=i1->createIterator();
    ASSERT_ANY_THROW( it->first());
    ASSERT_ANY_THROW( it->currentItem());
    ASSERT_ANY_THROW( it->next());
    ASSERT_TRUE(it->isDone());
    
   
}
TEST(midterm2Test,evaluateVisitor){
    Element* i1=new Integer(1);
    Element* i2=new Integer(2);
    Element* i3=new Integer(3);
    Element* set1=new Set();
    set1->add(i1);
    set1->add(i2);    
    set1->add(i3);    
    
    EvaluateVisitor* fsv=new EvaluateVisitor();
    set1->accept(fsv);
    ASSERT_NEAR(6,fsv->getResult(),0.0001);
    
}
#endif