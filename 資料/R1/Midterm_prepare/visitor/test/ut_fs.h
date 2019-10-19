#ifndef UT_FS_H
#define UT_FS_H

#include <sys/stat.h>
#include "../src/folder.h"
#include "../src/file.h"
#include "../src/info_content_visitor.h"
#include "../src/find_visitor.h"
#include "../src/node_iterator.h"

TEST(FileSystemTest,NodeIterator)
{
  Node * folder = new Folder("./test_data/folder");
  Node * test_data = new Folder("./test_data");
  Node * hello_cpp = new File("./test_data/hello.cpp");
  Node * a_out = new File("./test_data/folder/a.out");
  test_data->add(folder);
  test_data->add(hello_cpp);
  folder->add(a_out);
  NodeIterator * it = test_data->createIterator();
  it->first();
  ASSERT_EQ(4096, it->currentItem()->size());
  it->next();
  ASSERT_EQ(89, it->currentItem()->size());
  it->next();
  ASSERT_TRUE(it->isDone());
  ASSERT_ANY_THROW(it->currentItem());
  ASSERT_ANY_THROW(it->next());
}

/*TEST(MisTest, lstatOnFolder){
  const char * path = "./test_data";
  struct stat st;
  ASSERT_EQ(0, lstat(path, &st));
  ASSERT_EQ(4096, st.st_size);
  ASSERT_EQ(true, S_ISDIR(st.st_mode));
  ASSERT_EQ(false, S_ISREG(st.st_mode));
  ASSERT_EQ(false, S_ISLNK(st.st_mode));
}

TEST (FileSystemTest, Size){
  Node * test_data = new Folder ("./test_data");
  ASSERT_EQ(4096, test_data->size());
  Node * folder = new Folder("./test_data/folder");
  ASSERT_EQ(4096, folder->size());
  Node * hello_cpp = new File("./test_data/hello.cpp");
  ASSERT_EQ(89, hello_cpp->size());
  Node * a_out = new File("./test_data/folder/a.out");
  ASSERT_EQ(8432, a_out->size());
  test_data->add(folder);
  test_data->add(hello_cpp);
  ASSERT_EQ(2,test_data->numberOfChildren());
}*/

TEST (FileSystemTest, Visitor){
  Node * a_out = new File("./test_data/folder/a.out");
  Visitor * icv = new InfoContentVisitor();
  a_out->accept(icv);
  ASSERT_EQ(8432, icv->getContentSize());

  delete icv;
  Visitor * icv2 = new InfoContentVisitor();
  Node * folder = new Folder("./test_data/folder");
  folder->add(a_out);
  folder->accept(icv2);
  ASSERT_EQ(8432, icv2->getContentSize());

  Visitor * icv3 = new InfoContentVisitor();
  Node * test_data = new Folder("./test_data");
  Node * hello_cpp = new File("./test_data/hello.cpp");
  test_data->add(folder);
  test_data->add(hello_cpp);
  test_data->accept(icv3);
  ASSERT_EQ(8521,icv3->getContentSize());

}

TEST (, FileSearchItsSelf)
{
  Node * a_out = new File("./test_data/folder/a.out");
  Visitor *fv = new FindVisitor();
  a_out->accept(fv);
  ASSERT_EQ("a.out",fv->find("a.out"));
}
TEST (, FileSearchNotItsSelf)
{
  Node * a_out = new File("./test_data/folder/a.out");
  Visitor *fv = new FindVisitor();
  a_out->accept(fv);
  ASSERT_EQ("",fv->find("b.out"));
}
TEST (, FolderSearchItsSelf)
{
  Node * folder = new Folder("./test_data/folder");
  Visitor *fv = new FindVisitor();
  folder->accept(fv);
  ASSERT_EQ("",fv->find("folder"));
}
TEST (, FolderSearchNotItsSelf)
{
  Node * folder = new Folder("./test_data/folder");
  Visitor *fv = new FindVisitor();
  folder->accept(fv);
  ASSERT_EQ("",fv->find("test_data"));
}

TEST (, SearchFileInFolder)
{
  Node * folder = new Folder("./test_data/folder");
  Node * a_out = new File("./test_data/folder/a.out");
  Node * b_out = new File("./test_data/folder/b.out");
  Visitor *fv = new FindVisitor();
  Visitor *fv2 = new FindVisitor();

  folder->add(a_out);
  folder->add(b_out);
  folder->accept(fv);
  ASSERT_EQ("./a.out",fv->find("a.out"));

  folder->remove(b_out);
  folder->accept(fv2);
  ASSERT_EQ("",fv2->find("b.out"));
}

TEST (, SearchFolderInFolder)
{
  Node * test_data = new Folder ("./test_data");
  Node * folder = new Folder("./test_data/folder");
  test_data->add(folder);
  Visitor *fv = new FindVisitor();
  test_data->accept(fv);
  ASSERT_EQ("./folder",fv->find("folder"));
}

TEST (, SearchSameNameFileInFolder){
  Node * test_data = new Folder ("./test_data");
  Node * folder = new Folder("./test_data/folder");
  Node * folder2 = new Folder("./test_data/folder/folder");
  Node * a_out1 = new File("./test_data/folder/folder/a.out");
  Node * a_out2 = new File("./test_data/folder/a.out");
  Node * a_out3 = new File("./test_data/a.out");
  folder2->add(a_out1);
  folder->add(folder2);
  folder->add(a_out2);
  test_data->add(a_out3);
  test_data->add(folder);
  Visitor *fv = new FindVisitor();
  test_data->accept(fv);
  ASSERT_EQ("./folder\n./folder/folder",fv->find("folder"));
  Visitor *fv2 = new FindVisitor();
  test_data->accept(fv2);
  ASSERT_EQ("./a.out\n./folder/a.out\n./folder/folder/a.out",fv->find("a.out"));
}
#endif
