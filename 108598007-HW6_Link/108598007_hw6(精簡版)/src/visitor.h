#ifndef VISTOR_H
#define VISTOR_H


class Folder;
class File;
class Link;
class Iterator;
class Visitor
{
  public:
      virtual void visitFolder(Folder * folder) = 0;
      virtual void visitFile(File * file) = 0;
      virtual void visitLink(Link * link) = 0;
      virtual void reSetMatchNode(){}
      virtual Iterator * createIterator(){return nullptr;}
};

#endif