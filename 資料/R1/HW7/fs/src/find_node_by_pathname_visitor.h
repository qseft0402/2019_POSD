#ifndef FIND_NODE_BY_PATHNAME_VISITOR_H
#define FIND_NODE_BY_PATHNAME_VISITOR_H

#include "node_visitor.h"
#include <vector>
#include <string>

using namespace std;

class Node;

class FindNodeByPathnameVisitor : public NodeVisitor
{
    public:
        FindNodeByPathnameVisitor(vector<string>* pathnames);
        void visitFolder(Folder* folder);
        void visitFile(File* file);
        void visitLink(Link* link);
        Node* getNode() const;

    private:
        vector<string>* _pathnames;
        vector<string>::iterator _it;
        Node* _result;
};

#endif
