#include <iostream>
#include "filesystem_builder.h"
#include "node.h"
#include "folder.h"
#include "file.h"
#include "link.h"

FileSystemBuilder* FileSystemBuilder::_fsb=nullptr;

FileSystemBuilder::FileSystemBuilder():_root(nullptr),_subRoot(nullptr){

}

FileSystemBuilder* FileSystemBuilder::instance(){
  if(!_fsb)
      _fsb= new FileSystemBuilder();
  return _fsb;
}


void FileSystemBuilder::build(string path){
    if(Node::isFile(path.c_str())){
      _root = new File(path);
    }
    else if(Node::isLink(path.c_str())){
      _root = new Link(path);
    }
    else if(Node::isDir(path.c_str())){
        DIR * root;
        root = opendir(path.c_str());
        if(root==nullptr){
            throw std::string("Not Exist");
        }
        _root = new Folder(path);

        struct dirent * dp;

        while((dp = readdir(root)) != NULL) {
            if(std::string(dp->d_name) ==".." || std::string(dp->d_name)== "."){
              continue;
            }
            if (dp->d_type == DT_REG ) {
                Node * n = new File(std::string(path) + "/" + std::string(dp->d_name));
                _root->addChild(n);
            }
            else if(dp->d_type == DT_LNK){
                Node * n = new Link(std::string(path) + "/" + std::string(dp->d_name));
                _root->addChild(n);
            }
            else if(dp->d_type==DT_DIR){
                FileSystemBuilder fsb;
                fsb.build(std::string(path) + "/" + std::string(dp->d_name));
                _root->addChild(fsb.getRoot());
            }
        }
        closedir(root);
    }
}
Node * FileSystemBuilder::getRoot(){
    return _root;
}
