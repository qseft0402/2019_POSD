#include "find_visitor.h"
#include "node.h"
#include "file.h"
#include "folder.h"

FindVisitor::FindVisitor(): rootPath(""){
  _nodeName.clear();
  _nodePath.clear();
}

void FindVisitor::visitFile(File *file){
  if(rootPath.length() == 0){
    rootPath = file->getPath();
  }
  _nodeName.push_back(file->getName());
  _nodePath.push_back(file->getPath());
}

void FindVisitor::visitFolder(Folder *folder){
  if(rootPath.length() == 0){
    rootPath = folder->getPath();
  }
  else{
    _nodeName.push_back(folder->getName());
    _nodePath.push_back(folder->getPath());
  }
  // for(int i = 0; i < folder->numberOfChildren(); i++, it++){
  //   (*it)->accept(this);
  // }
  NodeIterator * it = folder->createIterator();
  for (it->first(); !it->isDone(); it->next())
  {
    it->currentItem()->accept(this);
  }
}

string FindVisitor::find(string target){
  vector<string> result;
  result.clear();
  for(int i = 0; i < _nodeName.size(); i++){
    if(target.compare(_nodeName.at(i)) == 0)
    {
      int lengthOfRootPath = rootPath.length();
      int lengthOfTargetPath = _nodePath.at(i).length();
      //cout << rootPath << endl;
      //cout << _nodePath.at(i) << endl;
      if(lengthOfRootPath != lengthOfTargetPath)
        result.push_back("." + _nodePath.at(i).substr(lengthOfRootPath, lengthOfTargetPath-lengthOfRootPath));
      else
        result.push_back(target);
    }
  }
  sort(result.begin(), result.end(), [](string a, string b){
    int countA = 0;
    int countB = 0;
    for(int i =0; i < a.length(); i++)
    {
      if(a[i] == '/')
      {
        countA++;
      }
    }
    for(int i =0; i < b.length(); i++)
    {
      if(b[i] == '/')
      {
        countB++;
      }
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
  return finalResult;
}
