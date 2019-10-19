#ifndef UT_FS_H
#define UT_FS_H

#include <sys/stat.h>
#include "../src/folder.h"
#include "../src/file.h"
#include "../src/info_content_visitor.h"
#include "../src/find_visitor.h"
/*
TEST(MisTest, lstatOnFolder){
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
}

TEST (FileSystemTest, NodeVisitor){
  Node * a_out = new File("./test_data/folder/a.out");
  NodeVisitor * icv = new InfoContentVisitor();
  a_out->accept(icv);
  ASSERT_EQ(8432, icv->getContentSize());
  delete icv;
  icv = new InfoContentVisitor();
  NodeVisitor * icv2 = new InfoContentVisitor();
  Node * folder = new Folder("./test_data/folder");
  folder->add(a_out);
  folder->accept(icv2);
  ASSERT_EQ(8432, icv2->getContentSize());
  NodeVisitor * icv3 = new InfoContentVisitor();
  Node * test_data = new Folder("./test_data");
  Node * hello_cpp = new File("./test_data/hello.cpp");
  test_data->add(folder);
  test_data->add(hello_cpp);
  test_data->accept(icv3);
  ASSERT_EQ(8521,icv3->getContentSize());

}
*/
TEST (, FileSearchItsSelf)
{
  Node * a_out = new File("./test_data/folder/a.out");
  NodeVisitor *fv = new FindVisitor("a.out");
  a_out->accept(fv);
  ASSERT_EQ("a.out",fv->findResult());
}/*
TEST (, FileSearchNotItsSelf)
{
  Node * a_out = new File("./test_data/folder/a.out");
  NodeVisitor *fv = new FindVisitor("b.out");
  a_out->accept(fv);
  ASSERT_EQ("",fv->findResult());
}
TEST (, FolderSearchItsSelf)
{
  Node * folder = new Folder("./test_data/folder");
  NodeVisitor *fv = new FindVisitor("folder");
  folder->accept(fv);
  ASSERT_EQ("",fv->findResult());
}
TEST (, FolderSearchNotItsSelf)
{
  Node * folder = new Folder("./test_data/folder");
  NodeVisitor *fv = new FindVisitor("test_data");
  folder->accept(fv);
  ASSERT_EQ("",fv->findResult());
}

TEST (, SearchFileInFolder)
{
  Node * folder = new Folder("./test_data/folder");
  Node * a_out = new File("./test_data/folder/a.out");
  Node * b_out = new File("./test_data/folder/b.out");
  NodeVisitor *fv = new FindVisitor("a.out");
  folder->add(a_out);
  folder->add(b_out);
  folder->accept(fv);
  ASSERT_EQ("./a.out",fv->findResult());
}

TEST (, SearchFolderInFolder)
{
  Node * test_data = new Folder ("./test_data");
  Node * folder = new Folder("./test_data/folder");
  test_data->add(folder);
  NodeVisitor *fv = new FindVisitor("folder");
  test_data->accept(fv);
  ASSERT_EQ("./folder",fv->findResult());
}

TEST (, SearchSameNameFileInFolder){
  Node * test_data = new Folder ("./test_data");
  Node * folder = new Folder("./test_data/folder");
  Node * folder2 = new Folder("./test_data/folder/folder");
  Node * a_out1 = new File("./test_data/folder/folder/a.out");
  Node * a_out2 = new File("./test_data/folder/a.out");
  Node * a_out3 = new File("./test_data/a.out");
  folder->add(folder2);
  folder2->add(a_out1);
  folder->add(a_out2);
  test_data->add(folder);
  test_data->add(a_out3);
  NodeVisitor *fv = new FindVisitor("folder");
  test_data->accept(fv);
  ASSERT_EQ("./folder\n./folder/folder",fv->findResult());
  NodeVisitor *fv2 = new FindVisitor("a.out");
  test_data->accept(fv2);
  ASSERT_EQ("./a.out\n./folder/a.out\n./folder/folder/a.out",fv2->findResult());
  NodeVisitor *fv3 = new FindVisitor("folder");
  folder->accept(fv3);
  ASSERT_EQ("./folder",fv3->findResult());
  fv3 = new FindVisitor("a.out");
  test_data->accept(fv3);
  ASSERT_EQ("./a.out\n./folder/a.out\n./folder/folder/a.out",fv3->findResult());
}

TEST(, FindVisitor){
  Node * test_data = new Folder ("./test_data");
  Node * folder = new Folder("./test_data/folder");
  Node * folder2 = new Folder("./test_data/folder/folder");
  Node * a_folder = new Folder("./test_data/a");
  Node * a_folder2 = new Folder("./test_data/a/a");
  Node * a_out1 = new File("./test_data/a/a/a.out");
  Node * a_out2 = new File("./test_data/folder/a.out");
  Node * a_out3 = new File("./test_data/a.out");
  test_data->add(a_folder);
  a_folder->add(a_folder2);
  folder->add(folder2);
  folder2->add(a_out1);
  folder->add(a_out2);
  test_data->add(folder);
  test_data->add(a_out3);
  NodeVisitor *fv = new FindVisitor("a.out");
  test_data->accept(fv);
  ASSERT_EQ("./a.out\n./folder/a.out\n./a/a/a.out",fv->findResult());
  NodeVisitor *fv2 = new FindVisitor("a");
  test_data->accept(fv2);
  ASSERT_EQ("./a\n./a/a",fv2->findResult());
}

TEST(, FolderFindFileOrFolderInSameName){
  Node * folder = new Folder("./test_data");
  Node * folder2 = new Folder("./test_data/test_data");
  Node * file = new File("./test_data/test_data/test_data");
  folder->add(folder2);
  folder2->add(file);
  NodeVisitor *fv = new FindVisitor("test_data");
  folder2->accept(fv);
  ASSERT_EQ("./test_data",fv->findResult());
  folder->accept(fv);
  ASSERT_EQ("./test_data\n./test_data/test_data",fv->findResult());
}

TEST(,NodeIterator){
  Node * folder = new Folder("./test_data/folder");
  Node * test_data = new Folder("./test_data");
  Node * hello_cpp = new File("./test_data/hello.cpp");
  Node * a_out = new File("./test_data/folder/a.out");
  test_data->add(folder);
  test_data->add(hello_cpp);
  folder->add(a_out);
  std::unique_ptr<NodeIterator> it(test_data->createIterator());
  it->first();
  ASSERT_EQ(4096, it->currentItem()->size());
  it->next();
  ASSERT_EQ(89, it->currentItem()->size());
  it->next();
  ASSERT_TRUE(it->isDone());
  ASSERT_ANY_THROW(it->currentItem());
  ASSERT_ANY_THROW(it->next());
}*/

#endif
