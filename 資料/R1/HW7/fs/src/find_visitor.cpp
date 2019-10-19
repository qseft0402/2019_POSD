#include "find_visitor.h"
#include "node_iterator.h"
#include "node.h"
#include "file.h"
#include "folder.h"
#include "link.h"

#include <iostream>
using namespace std;

FindVisitor::FindVisitor(string target): _rootPath(""), _target(target)
{
  _nodes.clear();
}

void FindVisitor::visitFile(File *file)
{
  _nodes.clear();
  if(_rootPath.length() == 0)
  {
    _rootPath = file->getPath();
  }
  _nodes.insert(pair<string, Node*>(file->getPath(), file));
}

void FindVisitor::visitFolder(Folder *folder)
{
  _nodes.clear();
  if(_rootPath.length() == 0)
  {
    _rootPath = folder->getPath();
  }
  else
  {
    _nodes.insert(pair<string, Node*>(folder->getPath(), folder));
  }
  NodeIterator *it = folder->createIterator();
  for(it->first(); !it->isDone(); it->next())
  {
    if(it->currentItem()->numberOfChildren() > 0)
    {
      NodeVisitor *subVisitor = new FindVisitor(_target);
      it->currentItem()->accept(subVisitor);
      NodeIterator *subNodes = subVisitor->createIterator();
      for(subNodes->first(); !subNodes->isDone(); subNodes->next())
      {
        _nodes.insert(pair<string, Node*>(subNodes->currentItem()->getPath(), subNodes->currentItem()));
      }
    }
    _nodes.insert(pair<string, Node*>(it->currentItem()->getPath(), it->currentItem()));
  }
}

void FindVisitor::visitLink(Link *link)
{
    link->getSource()->accept(this);
}

string FindVisitor::findResult()
{
  vector<string>result;
  NodeIterator *it = createIterator();
  for(it->first(); !it->isDone(); it->next())
  {
    cout << it->currentItem()->name()<< endl;
    if(it->currentItem()->name().compare(_target) == 0)
    {
      int lengthOfRootPath = _rootPath.length();
      int lengthOfTargetPath = it->currentItem()->getPath().length();
      if(lengthOfRootPath != lengthOfTargetPath)
        result.push_back("." + it->currentItem()->getPath().substr(lengthOfRootPath, lengthOfTargetPath - lengthOfRootPath));
      else
        result.push_back(_target);
    }
  }
  sort(result.begin(), result.end(), [](string a, string b)
  {
      int countA = 0;
      int countB = 0;
      for(int i = 0; i < a.length(); i++)
      {
        if(a[i] == '/')
          countA++;
      }
      for(int i = 0; i < b.length(); i++)
      {
        if(b[i] == '/')
          countB++;
      }
      return countA < countB;
  });
  string finalResult("");
  int i = 0;
  for(auto str : result){
    if(i > 0)
      finalResult += "\n";
    finalResult += str;
    i++;
  }
  _rootPath = "";
  return finalResult;
}
