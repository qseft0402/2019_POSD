#include "find_node_by_pathname_visitor.h"
#include "file.h"
#include "folder.h"
#include "link.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

FindNodeByPathnameVisitor::FindNodeByPathnameVisitor(vector<string>* pathnames) : _pathnames(pathnames) , _result(nullptr)
{
  _it = _pathnames->begin();
}

void FindNodeByPathnameVisitor::visitFolder(Folder *folder)
{
  /*
  string targetPath = ".";
  for (string pathname : *this->_pathnames)
  {
      targetPath += "/";
      targetPath += pathname;
  }
  string folderPath = folder->getPath();
  if (folderPath == targetPath)
  {
      _result = folder;
      return;
  }
*/
  if( _it != _pathnames->end())
  {
      if( (*_it).compare(folder->name()) == 0)
      {
          if(_it+1 != _pathnames->end())
          {
              _it++;
              NodeIterator* it = folder->createIterator();
              for (it->first(); !it->isDone(); it->next())
              {
                  it->currentItem()->accept(this);
              }
          }
          else
          {
              _result = folder;
          }
      }
  }
}

void FindNodeByPathnameVisitor::visitFile(File *file)
{
  if( _it != _pathnames->end())
    {
        if( (*_it).compare(file->name()) == 0)
        {
            _result = file;
        }
    }
  //int size = _pathnames->size();
  //cout << _pathnames->at(_pathnames->size()-1) << endl;
  /*int cc=1;
  Node* com;
  com = file;
  cout << "filename: " << file->name() << endl;
  for(int i=_pathnames->size(); i>0; i--)
  {
    if(_pathnames->at(i-1).compare(com->name()))
    {
      cc=0;
    }
    com = com->getParent();
  }
  if(cc)
  {
    _result = file;
  }*/
}

void FindNodeByPathnameVisitor::visitLink(Link *link)
{
  for (string pathname : *this->_pathnames)
  {
    if (pathname != link->name())
    {
      continue;
    }
    else
    {
      cout << "visitLink" << endl;
      _result = link;
      break;
    }
  }
}

Node* FindNodeByPathnameVisitor::getNode() const
{
    //cout << "naem : " << _result->numberOfChildren() << endl;
    return _result;
}
