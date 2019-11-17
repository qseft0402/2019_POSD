#ifndef UT_NODE_H
#define UT_NODE_H
using namespace std;
#include <gtest/gtest.h>
#include "../src/file.h"
#include "../src/node.h"
#include "../src/folder.h"
class TestNode :public ::testing::Test{
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

};



TEST_F(TestNode,ThrowString){
  try{
    notExistFile =new File("test/test_folder/Not_exist_file");
    ASSERT_EQ(true, false);
  }catch(std::string str){
    ASSERT_EQ("Node is not exist!",str);
  }
}
TEST_F(TestNode,getName){
    ASSERT_EQ("a.out",a_out->name());
}

TEST_F(TestNode,notFolder){
  try{
    notFile = new File("test/test_folder");
    ASSERT_EQ(true, false);
  }catch(std::string str){
    ASSERT_EQ("It is not File!",str);
  }
}

TEST_F(TestNode,FileFindNode){
    ASSERT_EQ("a.out",a_out->findNode("a.out"));
}
TEST_F(TestNode,FolderListNode){
    ASSERT_EQ("TA_folder a.out hello.txt", test_data->listNode());
}
TEST_F(TestNode,FolderFindNode1){
    ASSERT_EQ("./TA_folder/a.out\n./TA_folder/test_data/a.out\n./a.out", test_data->findNode("a.out"));
}



#endif
