#include <gtest/gtest.h>
#include "../src/file.h"
#include "../src/node.h"
#include "../src/folder.h"



TEST(TestNode,ThrowString){
  try{
    Node* a_out=new File("test/test_folder/Not_exist_file");
    ASSERT_EQ(true, false);
  }catch(std::string str){
    ASSERT_EQ("Node is not exist!",str);
  }
}
  TEST(TestNode,getName){
      Node* a_out=new File("test/test_folder/a.out");
      ASSERT_EQ("a.out",a_out->name());
}

TEST(TestNode,notFolder){
  try{
    Node * a_out = new File("test/test_folder");
    ASSERT_EQ(true, false);
  }catch(std::string str){
    ASSERT_EQ("It is not File!",str);
  }
}

TEST(TestNode,FileFindNode){

    Node * a_out = new File("test/test_folder/a.out");
    ASSERT_EQ("a.out",a_out->findNode("a.out"));
}
TEST(TestNode,FolderListNode){

    Node * hello_txt = new File("test/test_folder/test_data/hello.txt");
    Node * a_out = new File("test/test_folder/test_data/a.out");
    Node * folder = new Folder("test/test_folder/test_data/TA_folder");
    Node * test_data = new Folder("test/test_folder/test_data");

    test_data->addChild(a_out);
    test_data->addChild(folder);
    test_data->addChild(hello_txt);
    ASSERT_EQ("TA_folder a.out hello.txt", test_data->listNode());
}
TEST(TestNode,FolderFindNode1){

    Node * a_out1 = new File("test/test_folder/test_data/a.out");
    Node * a_out2 = new File("test/test_folder/test_data/TA_folder/a.out");
    Node * a_out3 = new File("test/test_folder/test_data/TA_folder/test_data/a.out");
    Node * hello_txt = new File("test/test_folder/test_data/hello.txt");
    Node * test_data1 = new Folder("test/test_folder/test_data");
    Node * test_data2 = new Folder("test/test_folder/test_data/TA_folder/test_data");
    Node * TA_folder=new Folder("test/test_folder/test_data/TA_folder");

    test_data1->addChild(a_out1);
    test_data2->addChild(a_out3);
    TA_folder->addChild(a_out2);
    TA_folder->addChild(test_data2);
    test_data1->addChild(TA_folder);
    test_data1->addChild(hello_txt);
    ASSERT_EQ("./a.out\n./TA_folder/a.out\n./TA_folder/test_data/a.out", test_data1->findNode("a.out"));
}
