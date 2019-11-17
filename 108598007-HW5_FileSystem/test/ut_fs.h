#ifndef UT_FS_H
#define UT_FS_H
using namespace std;
#include <gtest/gtest.h>
#include "../src/file.h"
#include "../src/node.h"
#include "../src/folder.h"
#include "../src/utilities.h"
class FSTest :public ::testing::Test{
protected:
  void SetUp(){
    a_out=new File("test/test_folder/a.out");
    a_out1 = new File("test/test_folder/test_data/a.out");
    a_out2=new File("test/test_folder/test_data/TA_folder/a.out");
    a_out3=new File("test/test_folder/test_data/TA_folder/test_data/a.out");
    hello_txt = new File("test/test_folder/test_data/hello.txt");

    folder = new Folder("test/test_folder/test_data/TA_folder");
    test_data = new Folder("test/test_folder/test_data");



    test_data2 = new Folder("test/test_folder/test_data/TA_folder/test_data");
    TA_folder=new Folder("test/test_folder/test_data/TA_folder");

    test_data->addChild(a_out1);
    test_data2->addChild(a_out3);
    TA_folder->addChild(a_out2);
    TA_folder->addChild(test_data2);
    test_data->addChild(TA_folder);
    test_data->addChild(hello_txt);

    test_data->addChild(a_out1);
    test_data->addChild(folder);
    test_data->addChild(hello_txt);

  }
  void TearDown(){
    delete a_out;
    delete a_out1;
    delete a_out2;
    delete a_out3;
    delete hello_txt;
    delete TA_folder;
    delete folder;
    delete test_data;
    delete test_data2;

  }
  Node* a_out;
  Node* a_out1;
  Node* a_out2;
  Node* a_out3;
  Node* hello_txt;
  Node* folder;
  Node* TA_folder;
  Node* test_data;
  Node* test_data2;
  Node* notExistFile;
  Node* notFile;
  Utilities ut;
  Iterator *it;
};



TEST_F(FSTest,ut_ListNode){

  ASSERT_EQ("TA_folder a.out hello.txt",ut.listNode(test_data));

  
}
TEST_F(FSTest,ut_FindNode){

  ASSERT_EQ("./TA_folder/a.out\n./TA_folder/test_data/a.out\n./a.out", ut.findNode(test_data,"a.out"));
}
TEST_F(FSTest,ut_FileListNode){
  try{
    ut.listNode(a_out);
    ASSERT_TRUE(false);
  }catch(string s){
    ASSERT_EQ("Not a directory", s);
  }
}

TEST_F(FSTest,ut_FileFindNode){

    ASSERT_EQ("a.out",ut.findNode(a_out,"a.out"));
   
}

TEST_F(FSTest,FolderIteratorEnd){
  try{
    
    it=test_data->createIterator();
    it->first();
    for(;!it->isDone();it->next());
    it->currentItem();
    ASSERT_TRUE(false);
  }catch(string s){
    ASSERT_EQ("No current item!", s);
  }
}

TEST_F(FSTest,FolderIteratorNextToEnd){
  try{
    
    it=test_data->createIterator();
    it->first();
    for(;!it->isDone();it->next());
    it->next();
    ASSERT_TRUE(false);
  }catch(string s){
    ASSERT_EQ("Moving past the end!", s);
  }
}

TEST_F(FSTest,NullIteratorFirst){
  try{
    it=a_out->createIterator();
    it->first();
    ASSERT_TRUE(false);
  }catch(string s){
    ASSERT_EQ("no child member", s);
  }
}

TEST_F(FSTest,NullIteratorCurrentItem){
  try{
    
    it=a_out->createIterator();
    it->currentItem();
    ASSERT_TRUE(false);
  }catch(string s){
    ASSERT_EQ("no child member", s);
  }
}


TEST_F(FSTest,NullIteratorNext){
  try{
    it=a_out->createIterator();
    it->next();
    ASSERT_TRUE(false);
  }catch(string s){
    ASSERT_EQ("no child member", s);
  }
}
TEST_F(FSTest,NullIteratorIsDone){
    it=a_out->createIterator();
    ASSERT_TRUE(it->isDone());

}

#endif
