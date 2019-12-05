#ifndef FILESYSTEM_BUILDER_H
#define FILESYSTEM_BUILDER_H
#include <string>
class Node;
class FileSystemBuilder  {
    protected:
        FileSystemBuilder();
    public:
        static FileSystemBuilder * instance();
        void build(std::string path);
        Node * getRoot();
    private:
        Node* _root;
        Node* _subRoot;

        static FileSystemBuilder* _fsb;
};

#endif
