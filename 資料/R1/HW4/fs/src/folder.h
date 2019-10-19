#ifndef FOLDER_H
#define FOLDER_H

#include <string>
#include <string.h>

#include "node.h"

int level = 0;
string stringArray[100];

class Folder : public Node {
public:
Folder(const char* path) : Node(path)
{
}

void add(Node *node)
{
        _children.push_back(node);
}

int infoContent() const
{
        int sum = 0;
        for (int i = 0; i < _children.size(); i++)
        {
                sum += _children[i]->infoContent();
        }
        return sum;
}

int numberOfChildren() const
{
        return _children.size();
}
int cntNodePath(string nodeName) const
{
    int cnt = 0;
    for (int i = 0; i < _children.size(); i++)
    {
        if(_children[i]->name() == nodeName)
        {
            cnt+=1;
            stringArray[level] = _children[i]->nodePath();
            level+=1;
        }
    }
    for (int i = 0; i < _children.size(); i++)
    {
        if(_children[i]->numberOfChildren() > 0)
        {
            cnt += _children[i]->cntNodePath(nodeName);
        }
    }
    return cnt;
}
/*int totalFilePathcount(string nodePath) const
{
    int cnt = 0;
    for(int i = 0; i< nodePath.size(); i++)
    {
        if(nodePath[i] == '/')
        {
            cnt+=1;
        }
    }
    cnt+=1;
    return cnt;
}*/
string find(string nodeName) const
{
    int cnt = cntNodePath(nodeName);
    string sContent = "";
    string sFinal = "";
    string sFinalndoePath = this->nodePath();

    if (cnt == 0 )
    {
        return "";
    }
    else
    {
        for (int i=0 ; i<cnt ; i++)
        {
            sContent = stringArray[i].erase(0, sFinalndoePath.length());
            if (i == 0)
            {
              sFinal = dot + sContent;
            }
            else
            {
              sFinal = sFinal + slashN;
              sFinal = sFinal + dot + sContent;
            }

        }
        for(int r =0; r < 100 ; r++)
        {
          level = 0;
          stringArray[r] = "";
        }
        return sFinal;
    }
}
/*string find(string nodeName) const
{
    int cnt = cntNodePath(nodeName);
    cout << "totalFilecount: " << cnt << endl;
    cout << "totalLevel: " << level << endl;
    //cout << stringArray[1] << endl;

    if(cnt == 0)
    {
        return "";
    }
    /*else if(cnt == 1)
    {
        string rootNodePath = this->nodePath();
        stringstream cntRootNodePathSS(rootNodePath);
        stringstream cntWantNodePathSS(stringArray[0]);
        stringstream finalNodePathSS;
        string sFinal;
        int rootCountNode = totalFilePathcount(rootNodePath);
        cout << "rootCountNode" << rootCountNode << endl;
        int wantCountNode = totalFilePathcount(stringArray[0]);
        cout << "wantCountNode" << wantCountNode << endl;
        //int sub = wantCountNode - rootCountNode;
        string rootItemPathArray[rootCountNode];
        string wantItemPathArray[wantCountNode];

        int j=0;
        while(getline(cntRootNodePathSS, rootItemPathArray[j], '/'))
        {
            j+=1;
        }
        j=0;
        while(getline(cntWantNodePathSS, wantItemPathArray[j], '/'))
        {
            j+=1;
        }

        finalNodePathSS << "./";
        for(int i=rootCountNode; i<wantCountNode-1; i++)
        {
            finalNodePathSS << wantItemPathArray[i];
            finalNodePathSS << "/";
        }
        finalNodePathSS << wantItemPathArray[wantCountNode-1];
        finalNodePathSS >> sFinal;

        for(int r = 0;r<100;r++)
        {
            level = 0;
            stringArray[r] = "";
        }
        return sFinal;
    }
    else
    {
        string rootNodePath = this->nodePath();
        stringstream cntRootNodePathSS(rootNodePath);
        int rootCountNode = totalFilePathcount(rootNodePath);

        stringstream cntWantNodePathSS[cnt];
        for(int i = 0;i < cnt; i++)
        {
            cntWantNodePathSS[i] << stringArray[i];
        }
        stringstream finalNodePathSS;
        string sFinal;
        string sFinalnext;

        int wantCountNode[cnt];
        for(int i = 0;i < cnt; i++)
        {
            wantCountNode[i] = totalFilePathcount(stringArray[i]);
        }

        string rootItemPathArray[rootCountNode];
        string wantItemPathArray[cnt][100];

        int j=0;
        while(getline(cntRootNodePathSS, rootItemPathArray[j], '/'))
        {
            j+=1;
        }

        j=0;
        for(int q=0; q < cnt; q++)
        {
            while(getline(cntWantNodePathSS[q], wantItemPathArray[q][j], '/'))
            {
                j+=1;
            }
            j=0;
        }
        for(int t = 0; t < cnt-1; t++) // 0, 2
        {
            finalNodePathSS << "./";
            for(int i = rootCountNode; i < wantCountNode[t]-1; i++) //2 4-1
            {
                finalNodePathSS << wantItemPathArray[t][i];
                finalNodePathSS << "/";
            }
            finalNodePathSS << wantItemPathArray[t][wantCountNode[t]-1];
            finalNodePathSS << "\n";
        }
        finalNodePathSS << "./";
        for(int k = rootCountNode; k < wantCountNode[cnt-1]-1; k++) // 2, 5-1
        {
            finalNodePathSS << wantItemPathArray[cnt-1][k];
            finalNodePathSS << "/";
        }
        finalNodePathSS << wantItemPathArray[cnt-1][wantCountNode[cnt-1]-1];

        finalNodePathSS >> sFinal;
        for(int g = 0; g < cnt-1; g++)
        {
            finalNodePathSS >> sFinalnext;
            sFinal = sFinal + "\n";
            sFinal = sFinal + sFinalnext;
        }

        for(int r = 0;r<100;r++)
        {
            level = 0;
            stringArray[r] = "";
        }
        return sFinal;
    }
}*/

private:
std::vector<Node *> _children;
std::vector<string> filePath;
string dot = {"."};
string slashN = {"\n"};
};

#endif //FOLDER_H
