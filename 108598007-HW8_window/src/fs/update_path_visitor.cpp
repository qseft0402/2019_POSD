#include "update_path_visitor.h"
#include "folder.h"
#include "file.h"
#include "link.h"

UpdatePathVisitor::UpdatePathVisitor(){}
void UpdatePathVisitor::visitFolder(Folder * folder){
    // folder->updateParentPath(folder->getParentPath());
    Iterator* it=folder->createIterator();
    for(it->first();!it->isDone();it->next()){
        Node* currentNode=it->currentItem();
        // cout<<"updatVS path:"<<currentNode->getPath()<<endl;
        currentNode->updateParentPath(folder->getPath());
        if(currentNode->getChildrenSize()>0){
            currentNode->accept(this);
        }
    }
}

void UpdatePathVisitor::visitFile(File* file){
    // cout<<file->getPath()<<endl;
    file->updateParentPath(file->getParentPath());
    // cout<<file->getPath()<<endl;

}


void UpdatePathVisitor::visitLink(Link * link){
    link->updateParentPath(link->getParentPath());
    // link->getSource()->updateParentPath(link->getParentPath());
}
