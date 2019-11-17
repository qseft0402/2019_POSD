#ifndef UT_FS_H
#define UT_FS_H
using namespace std;
#include <gtest/gtest.h>
#include "../src/file.h"
#include "../src/node.h"
#include "../src/folder.h"
#include "../src/utilities.h"
#include "../src/link.h"
#include "../src/find_visitor.cpp"
#include "../src/update_path_visitor.cpp"


class FSTest :public ::testing::Test{
protected:
  void SetUp(){
    try{
    a_out=new File("test/test_folder/a.out");
    a_out1 = new File("test/test_folder/test_data/a.out");
    a_out2=new File("test/test_folder/test_data/TA_folder/a.out");
    a_out3=new File("test/test_folder/test_data/TA_folder/test_data/a.out");
    a_out4=new File("test/test_folder/test_data/test_data/a.out");
    hello_txt = new File("test/test_folder/test_data/hello.txt");

    folder = new Folder("test/test_folder/test_data/TA_folder");
    test_data = new Folder("test/test_folder/test_data");
    test_txt=new File("test/test.txt");
    test_data1=new Folder("test/test_folder/test_data/test_data");

    test_data2 = new Folder("test/test_folder/test_data/TA_folder/test_data");
    TA_folder=new Folder("test/test_folder/test_data/TA_folder");
    link =new Link("test/test_folder/toa");
    link->addLink(a_out1);

    }catch(string s){
      cout<<"setup "<<s<<endl;
    }
    test_data->addChild(a_out1);
    test_data->addChild(test_data1);
    test_data1->addChild(a_out4);
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
    delete a_out4;
    delete hello_txt;
    delete TA_folder;
    delete folder;
    delete test_data;
    delete test_data1;
    delete test_data2;
    delete test_txt;
    delete link;
  }
  Node* a_out;
  Node* a_out1;
  Node* a_out2;
  Node* a_out3;
  Node* a_out4;
  Node* hello_txt;
  Node* folder;
  Node* TA_folder;
  Node* test_data;
  Node* test_data1;
  Node* test_data2;
  Node* notExistFile;
  Node* notFile;
  Utilities ut;
  Iterator *it;
  Node* test_txt;
  Node* link;
};



TEST_F(FSTest,ut_ListNode){
  ASSERT_EQ("TA_folder a.out hello.txt test_data",ut.listNode(test_data));
  
}
TEST_F(FSTest,ut_FindNode){

  ASSERT_EQ("./TA_folder/a.out\n./TA_folder/test_data/a.out\n./a.out\n./test_data/a.out", ut.findNode(test_data,"a.out"));
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
TEST_F(FSTest,NotALink){
  
  try{
    Node* link =new Link("test/test_folder/a.out");
    ASSERT_TRUE(false);
  }catch(string s){
    ASSERT_EQ("It is not Link!", s);
  }
  try{
    Link link("test/test_folder");
    ASSERT_TRUE(false);
  }catch(string s){
    ASSERT_EQ("It is not Link!", s);
  }
}
TEST_F(FSTest,addLink){
  try{
    link->addLink(a_out);
    // cout<<link->getSource()->getPath()<<endl;
    ASSERT_EQ(a_out->getPath(),link->getSource()->getPath());
    link->addLink(a_out1);
    ASSERT_EQ(a_out1->getPath(),link->getSource()->getPath());
  }catch(string s){
    ASSERT_EQ("It is not Link!", s);
  }
}

TEST_F (FSTest, NodeTypeError)
{
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

TEST_F(FSTest,FodlerVisitorFindResult){
  try{
  FindVisitor* visitor=new FindVisitor("a.out");
  test_data->accept(visitor);
  ASSERT_EQ("./TA_folder/a.out\n./TA_folder/test_data/a.out\n./a.out\n./test_data/a.out",visitor->findResult());
  
  }catch(string s){
    ASSERT_TRUE(false);
  }


}

TEST_F(FSTest,FileVisitorFindResult){
    FindVisitor* visitor=new FindVisitor("a.out");
    a_out->accept(visitor);
    ASSERT_EQ("a.out",visitor->findResult());
   
}
TEST_F(FSTest,LinkVisitorFindResult){
  try{
    FindVisitor* visitor=new FindVisitor("a.out");
   
    link->accept(visitor);
    // ASSERT_EQ("toa",visitor->findResult());
  }catch(string s){
    cout<<s<<endl;
  }
   
}
TEST_F(FSTest,VisitorDifferentFolder1){
  FindVisitor * fv = new FindVisitor("a.out");
  test_data->accept(fv);
  string result1 = fv->findResult(); //result1 will be "./a.out\n./folder/a.out"
  ASSERT_EQ("./TA_folder/a.out\n./TA_folder/test_data/a.out\n./a.out\n./test_data/a.out",result1);
  test_data2->accept(fv);
  string result2 = fv->findResult(); //result1 will be "./a.out\n./folder/a.out"
  ASSERT_EQ("./a.out",result2);
}
TEST_F(FSTest,FileRename){
  struct stat _st;
  UpdatePathVisitor * upv=new UpdatePathVisitor();
  ASSERT_EQ("test.txt",test_txt->name());
  // ASSERT_EQ("test/test.txt",test_txt->getPath());
  if (lstat("test/test.txt", &_st) != 0)
    FAIL();

  test_txt->renameNode("test1.txt");
  test_txt->accept(upv);
  ASSERT_EQ("test1.txt",test_txt->name());
  // ASSERT_EQ("test/test1.txt",test_txt->getPath());
  if (lstat("test/test1.txt", &_st) != 0)
    // FAIL();
  cout<<"rename test2.txt"<<endl;
  test_txt->renameNode("test2.txt");
  test_txt->accept(upv);
  ASSERT_EQ("test2.txt",test_txt->name());
  // ASSERT_EQ("test/test2.txt",test_txt->getPath());
  if (lstat("test/test2.txt", &_st) != 0)
    FAIL();

  test_txt->renameNode("test3.txt");
  test_txt->accept(upv);
  ASSERT_EQ("test3.txt",test_txt->name());
  // ASSERT_EQ("test/test3.txt",test_txt->getPath());
  if (lstat("test/test3.txt", &_st) != 0)
    FAIL();
 
  test_txt->renameNode("test.txt");
  test_txt->accept(upv);
  ASSERT_EQ("test.txt",test_txt->name());
  // ASSERT_EQ("test/test.txt",test_txt->getPath());
  if (lstat("test/test.txt", &_st) != 0)
    FAIL();
}


TEST_F(FSTest,FindFolder){
  
  FindVisitor * fv = new FindVisitor("a.out");
  test_data->accept(fv);
  string result1 = fv->findResult(); //result1 will be "./a.out\n./folder/a.out"
  ASSERT_EQ("./TA_folder/a.out\n./TA_folder/test_data/a.out\n./a.out\n./test_data/a.out",result1);

}

TEST_F(FSTest,VisitorDifferentFolder){
  FindVisitor * fv = new FindVisitor("a.out");
  test_data1->accept(fv);
  string result1 = fv->findResult(); //result1 will be "./a.out\n./folder/a.out"
  ASSERT_EQ("./a.out",result1);
  // cout<<"change!!"<<endl;
  TA_folder->accept(fv);
  string result2 = fv->findResult(); //result1 will be "./a.out\n./folder/a.out"
  ASSERT_EQ("./a.out\n./test_data/a.out",result2);

}

TEST_F(FSTest,UpdateVisitorFolder){
    struct stat _st;
    UpdatePathVisitor * upv = new UpdatePathVisitor();
  try{
    test_data->renameNode("TA2_folder");
    ASSERT_EQ("TA2_folder", test_data->name()); // Check the node name in your own file system!
    test_data->accept(upv); 
    ASSERT_EQ("test/test_folder/TA2_folder", test_data->getPath()); // Check the path of itself!
    ASSERT_EQ("test/test_folder/TA2_folder/TA_folder/test_data/a.out", a_out3->getPath()); // Check the path of child node!
    if (lstat("test/test_folder/TA2_folder", &_st) != 0)
        FAIL(); // Check the physical node name!

    a_out1->renameNode("b.out");
    a_out1->accept(upv);
//-----------------------------------------------------------------------------------------------
    // cout<<"test_data2 path: "<<test_data2->getPath()<<endl;
    test_data2->renameNode("TA2_folder");
    ASSERT_EQ("TA2_folder", test_data2->name()); // Check the node name in your own file system!
    test_data2->accept(upv); 
    ASSERT_EQ("test/test_folder/TA2_folder/TA_folder/TA2_folder", test_data2->getPath()); // Check the path of itself!
    ASSERT_EQ("test/test_folder/TA2_folder/TA_folder/TA2_folder/a.out", a_out3->getPath()); // Check the path of child node!
    if (lstat("test/test_folder/TA2_folder/TA_folder/TA2_folder", &_st) != 0)
        FAIL(); // Check the physical node name!

   
//-----------------------------------------------------------------------------------------------
    test_data1->renameNode("TA2_folder");
    test_data1->accept(upv);
    ASSERT_EQ("test/test_folder/TA2_folder/TA2_folder", test_data1->getPath()); // Check the path of itself!
    ASSERT_EQ("test/test_folder/TA2_folder/TA2_folder/a.out", a_out4->getPath()); // Check the path of child node!
    if (lstat("test/test_folder/TA2_folder/TA2_folder", &_st) != 0)
      FAIL(); // Check the physical node name!
    test_data->renameNode("test_data");
    test_data->accept(upv);
    test_data1->renameNode("test_data");
    test_data1->accept(upv);
    test_data2->renameNode("test_data");
    test_data2->accept(upv); 
    a_out1->renameNode("a.out");
    a_out1->accept(upv);
     }catch(exception e){
      cout<<"exception!!!"<<e.what()<<endl;
    }catch(string s){
      cout<<"string!!!"<<s<<endl;

    }
}

TEST_F(FSTest,UpdateVisitorFile){
  UpdatePathVisitor * upv = new UpdatePathVisitor();
  // cout<<a_out->getPath()<<endl;
  a_out->renameNode("b.out");
  a_out->accept(upv);
  // cout<<a_out->getPath()<<endl;

  ASSERT_EQ("test/test_folder/b.out", a_out->getPath()); // Check the path of itself!
  a_out->renameNode("a.out");

}
// TEST_F(FSTest,UpdateVisitorLink){
//   UpdatePathVisitor * upv = new UpdatePathVisitor();
  

// }
#endif
