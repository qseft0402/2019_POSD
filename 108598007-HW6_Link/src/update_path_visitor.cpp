#include "update_path_visitor.h"
#include "folder.h"
#include "file.h"
#include "link.h"

UpdatePathVisitor::UpdatePathVisitor(){}
void UpdatePathVisitor::visitFolder(Folder * folder){
    Iterator* it=folder->createIterator();
    for(it->first();!it->isDone();it->next()){
        Node* currentNode=it->currentItem();
        currentNode->updateParentPath(folder->getPath());
        if(currentNode->getChildrenSize()>0){
            currentNode->accept(this);
        }
    }
}

void UpdatePathVisitor::visitFile(File* file){
    file->updateParentPath(file->getParentPath());

}


void UpdatePathVisitor::visitLink(Link * link){
    link->updateParentPath(link->getParentPath());
}
