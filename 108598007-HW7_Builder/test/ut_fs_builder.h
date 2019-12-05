#ifndef UT_FS_BUILDER_H
#define UT_FS_BUILDER_H
#include <gtest/gtest.h>
#include "../src/filesystem_builder.cpp"
#include "../src/file.h"
#include "../src/folder.h"
#include "../src/link.h"
#include "../src/find_visitor.h"
#include "../src/iterator.h"

TEST(FileSystemBuilder, NodeTypeError){
  File* a_out=new File("./test/test_folder/a.out");

  try{
  new File("./123"); //If the node doesn't exist, you should throw string "Node is not exist!"
  }catch(string s){
     ASSERT_EQ("Node is not exist!", s);
  }
    try{
  new File("./test/test_folder/test_data"); //If the File doesn't exist, you should throw string "It is not File!"
  }catch(string s){
     ASSERT_EQ("It is not File!", s);
  }
    try{
  new Folder("./test/test_folder/a.out"); //If the Folder doesn't exist, you should throw string "It is not Folder!"

   }catch(string s){
     ASSERT_EQ("It is not Folder!", s);
  }
    try{
    new Link("./test/test_folder/a.out", a_out); //If the Link doesn't exist, you should throw string "It is not Link!"
   }catch(string s){
     ASSERT_EQ("It is not Link!", s);
  }

}

TEST(FileSystemBuilder, file){
    FileSystemBuilder * fb = FileSystemBuilder::instance();

    fb->build("test/test_folder/a.out");
    ASSERT_EQ("a.out", fb->getRoot()->name());
    ASSERT_EQ("test/test_folder/a.out", fb->getRoot()->getPath());

    fb->build("test/test_folder/test_data/a.out");
    ASSERT_EQ("a.out", fb->getRoot()->name());
    ASSERT_EQ("test/test_folder/test_data/a.out", fb->getRoot()->getPath());



}
// void print(Iterator* it){
//     for(it->first();!it->isDone();it->next()){
//         cout<<it->currentItem()->getPath()<<endl;
//         if(it->currentItem()->getType()==2)
//             print(it->currentItem()->createIterator());
//     }
// }
TEST(FileSystemBuilder, folder){

    FileSystemBuilder * fb = FileSystemBuilder::instance();
    // ASSERT_EQ("hw", fb->getRoot()->name());
    // ASSERT_EQ("test/TA_folder/hw", fb->getRoot()->getPath());
    // Iterator* it=(fb->getRoot())->createIterator();
    // it->first();
    // ASSERT_EQ("a.out",it->currentItem()->name());
    // it->next();
    // ASSERT_TRUE(it->isDone());
    try{
    fb->build("test/test_folder");
    // cout<<"UT!! "<<fb->getRoot()->getPath()<<endl;
    ASSERT_EQ("test_folder", fb->getRoot()->name());
    ASSERT_EQ("test/test_folder", fb->getRoot()->getPath());
    Iterator* it=(fb->getRoot())->createIterator();
    it->first();
    ASSERT_EQ("a.out",it->currentItem()->name());

    // cout<<it->currentItem()->getPath()<<endl;;
    it->next();
    ASSERT_EQ("test_data",it->currentItem()->name());
    it->next();
    ASSERT_EQ("toa",it->currentItem()->name());
    it->next();
    ASSERT_TRUE(it->isDone());
  }catch(string s){
    cout<<s<<endl;
  }
    // ASSERT_EQ("./a.out\n./test_data/TA_folder/a.out\n./test_data/TA_folder/test_data/a.out\n./test_data/a.out\n./test_data/test_data/a.out",visitor->findResult());

}

#endif
