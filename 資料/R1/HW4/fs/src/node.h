#ifndef NODE_H
#define NODE_H
#include <sys/stat.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Node
{
public:
Node(const char * path) : _path(path)
{
    lstat(_path, &_st);

    string str(_path);
    _nodeName = str;
    _nodePath = _nodeName;
    _nodeName = str.substr(str.rfind("/")+1);
}

int size() const
{
    return _st.st_size;
}

virtual int infoContent() const
{
    return size();
}

virtual void add(Node *node)
{
    throw std::string("unable to add");
}

virtual int numberOfChildren() const
{
    return 0;
}
virtual int cntNodePath(string) const
{
    return 1;
}
virtual int totalFilePathcount(string) const
{
    return 1;
}
virtual string find(string nodeName) const
{
    if(this->name() == nodeName)
    {
            return this->name();
    }
    else
    {
            return "";
    }
}
string name() const
{
    return _nodeName;
}
string nodePath() const
{
    return _nodePath;
}

private:
const char * _path;
struct stat _st;
string _nodePath;
string _nodeName;
};

#endif
