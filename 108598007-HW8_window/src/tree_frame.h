#ifndef TREE_FRAME_H
#define TREE_FRAME_H
using namespace std;
#include <wx/treectrl.h>
#include "fs/filesystem_builder.cpp"
#include "fs/update_path_visitor.cpp"
#include "text_frame.cpp"
#include <thread>
#include <fstream>
class TreeFrame : public wxFrame
{
public:
  string rootPath="test";
  TreeFrame(const wxChar *title, int xpos, int ypos, int width, int height):wxFrame((wxFrame *) nullptr, -1, title, wxPoint(xpos, ypos), wxSize(width, height))
  {
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    _tree = new wxTreeCtrl(this, wxID_ANY, wxPoint(0,0), wxSize(150,200), wxTR_HAS_BUTTONS  | wxTR_SINGLE );
    Node* root=SetFileSystem(rootPath);
    _root=root;
     Folder * folder = dynamic_cast<Folder *> (root);

    // cout<<"count!: "<<folder->getChild("ffff")->getPath()<<endl;
    updateTree(folder);
    _textArea=new wxTextCtrl(this, -1, _T("you can choice file to show in textbox..."),
		wxPoint(170,0),  wxSize(700,500), wxTE_MULTILINE);
    _saveBtn=new wxButton(this,BUTTON_Hello,_T("Save"),wxPoint(170,510),wxSize(700,100),0);
    // _tree->Bind(wxEVT_LEFT_DOWN  , &TreeFrame::toggle_item_onClick, this);
    
  }

  string ReadFile(string path){
    std::ifstream in(path.c_str());
  
    // Check if object is valid
    if(!in)
    {
      std::cerr << "Cannot open the File : "<<path<<std::endl;
      return nullptr;
    }
    std::string str;
    std::string allStr="";
    // Read the next line from File untill it reaches the end.
    while (std::getline(in, str))
    {
      // Line contains string of length > 0 then save it in vector
      if(str.size() > 0)
        allStr+=str+"\n";
      
    }
    //Close The File
    in.close();
    return allStr;
  }
  // wxTreeEvent& _event=nullptr;
  void read_file_item_onClick(wxTreeEvent &event)
{
  // cout<<"toggle_item_onclick"<<endl;
  try{
    // wxPoint mouse_position = event.GetPosition();
    // int temp_num = wxTREE_HITTEST_ONITEMLABEL;
    // _event=event;
    // wxTreeItemId itemId = _tree->HitTest(mouse_position, temp_num);
   
    wxTreeItemId itemId = event.GetItem();
    _updateItemSizeId=itemId;
    std::cout << itemId<< std::endl;
    // cout<<"here"<<endl;
    // cout<<"going to find "<<itemId<<endl;
    Node* node=getNodeById(itemId,_root);
    // cout<<" id= "<<itemId<<endl;
    _filePath=node->getPath();
    if(!node) cout<<"NULLPTR"<<endl;
    else{
      if(node->getType()==1){
        // cout<<"onclick:"<<node->getPath()<<endl;
        // cout<<"here2"<<endl;
        _textArea->LoadFile(wxT_2(node->getPath()));
      }
    }
    
    // string fileStr=ReadFile(node->getPath());
    
    // cout<<"onClick1!!!\n"<<fileStr<<endl;
  }catch(exception e){
    cout<<e.what() ;
  } 

}

void updateTree(Node* root){
    Iterator* it=root->createIterator();
    // cout<<"updateTree root="<<root->getPath()<<endl;
    wxTreeItemId rootId = _tree->AddRoot(wxT_2(root->name()+", "+to_string(root->size())));
    root->setWxTreeItemId(rootId);
    for(it->first();!it->isDone();it->next()){
      Node* node=it->currentItem();
      if(node->getType()==1){
        // cout<<"build!! "<<node->getPath()<<endl;
        wxTreeItemId id=_tree->AppendItem(rootId, wxT_2(node->name()+", "+to_string(node->size())));
        node->setWxTreeItemId(id);
        // cout<<"build!! id="<<node->getWxTreeItemId()<<endl;

        
      }else{
        wxTreeItemId id=_tree->AppendItem(rootId, wxT_2(node->name()+", "+to_string(node->size())));
        node->setWxTreeItemId(id);
        updateTreeItem(id,node);
      }
    }
    _tree->ExpandAllChildren(rootId);
}
void updateTreeItem(wxTreeItemId pid,Node* subRoot){
    Iterator* it=subRoot->createIterator();
    for(it->first();!it->isDone();it->next()){
      Node* node=it->currentItem();
      
        wxTreeItemId id =_tree->AppendItem(pid, wxT_2(node->name()+", "+to_string(node->size())));
        node->setWxTreeItemId(id);
      if(node->getType()==2){
        
        updateTreeItem(id,node);
      }
    }
}

Node* SetFileSystem(string rootPath){
  FileSystemBuilder* fsb=FileSystemBuilder::instance();
  fsb->build(rootPath);
  Node* root=fsb->getRoot();
  // Node* root=new Folder(rootPath);
  // cout<<"SetFileSystem :"<<root->name()<<endl;
  return root;

}
void ShowMessage3(string newName,string oldName) 
{
  wxMessageDialog *dial= new wxMessageDialog(NULL, 
      wxT("label edited: "+newName+"-- old name was "+oldName), wxT("Confirm"), 
      wxYES_NO | wxCANCEL | wxNO_DEFAULT | wxICON_QUESTION);
      dial->ShowModal();
}
void ShowMessage_Save() 
{
  wxMessageDialog *dial= new wxMessageDialog(NULL, 
      wxT("You want save?"), wxT("Confirm"), 
      wxYES_NO | wxCANCEL | wxNO_DEFAULT | wxICON_QUESTION);
      dial->ShowModal();
}
void OnEdit(wxTreeEvent& event)
{
  
  wxTreeItemId itemId=event.GetItem();
  std::cout << itemId<< std::endl;
  Node* node=getNodeById(itemId,_root);
  if(!node){
    cout<<"NULL!"<<endl;
  }else{
    try{
      string newName=getStrName(event.GetLabel().ToStdString());
      string oldName=getStrName(_tree->GetItemText(itemId).ToStdString());

      cout<<"new!! "<<newName<<endl;
      cout<<"old!! "<<oldName<<endl;

      if(newName==""){//if noting to change
        // cout<<"same!!"<<endl;
        return;
      } 
      cout<<node->getPath()<<endl;
      ShowMessage3(newName,oldName);
      // if(_mesAnswer==wxYES) cout<<"Yes!"<<endl;
      // else if(_mesAnswer==wxNO) cout<<"NO!"<<endl;
      // else if(_mesAnswer==wxCANCEL) cout<<"Cancel!"<<endl;

      UpdatePathVisitor * upv = new UpdatePathVisitor();
      node->renameNode(newName);
      node->accept(upv); 
      cout<<node->getPath()<<endl;
      _tree->SetItemText(itemId,wxString(newName+", "+to_string(node->getSize())));
      event.Veto();
    }catch(exception e){
      cout<<e.what()<<endl;
    }
    // cout<<(a->getChild("file2"))->getPath()<<endl;
  }
  std::cout << _tree->GetItemText(itemId)<< std::endl;
  

}
void updataItemSize(wxTreeItemId itemId,Node* node){
  cout<<"update size!:"<<node->getSize()<<endl;

  // Node* nodeTemp=new File(node->getPath());
  node->updateSize();
  _tree->SetItemText(itemId,wxString(node->name()+", "+to_string(node->getSize())));
  _tree->Refresh();

}
string getStrName(string str){
  size_t  pos=str.find(',');
  string temp;
  if(pos!=std::string::npos){
    temp=str.erase(pos,str.length());
    cout<<temp<<endl;
  }
  else{
    temp=str;
  }
  return temp;
}
Node* getNodeById(wxTreeItemId id,Node* root){
  Folder * folder = dynamic_cast<Folder *> (root);
  // cout<<"getNodeByid root= "<<folder->getPath()<<"  "<<folder->getChild("ffff")->getWxTreeItemId()<<endl;
  if(root->getWxTreeItemId()==id){
    return root;
  }else{
    Iterator* it=folder->createIterator();
    // cout<<"getNodeById count!!"<<folder->getChildrenSize()<<endl;
    
    for(it->first();!it->isDone();it->next()){
      Node* node=it->currentItem();
      // cout<<"in get node "<<node->getPath()<<" id="<<node->getWxTreeItemId()<<endl;
      if(node->getWxTreeItemId()==id){
        // cout<<"find! "<<node->getWxTreeItemId()<<endl;
        return node;
      }
    }

    for(it->first();!it->isDone();it->next()){
      Node* node=it->currentItem();
        if(node->getType()==2)
          return getNodeById(id,node);
      }
    
  }
  
return nullptr;


}
void test(wxTreeEvent& event){
  cout<<"TEST!!"<<endl;
}
void DClick(wxTreeEvent& event){
  cout<<"DClick!!"<<endl;
  _tree->EditLabel(event.GetItem());
}
void saveBtnFunc(wxCommandEvent& event){
  cout<<"ID:"<<event.GetId()<<endl;
  cout<<"save!!"<<endl;
  cout<<_textArea->GetLineText(0)<<endl;
  cout<<_textArea->GetNumberOfLines()<<endl;
  ShowMessage_Save();

  cout<<"going to save " <<_filePath<<endl;
  _textArea->SaveFile(wxT_2(_filePath));
  Node* node=getNodeById(_updateItemSizeId,_root);
  updataItemSize(_updateItemSizeId,node);
}
  wxTreeCtrl *_tree;
private:
  DECLARE_EVENT_TABLE()
  Node* _root;
  int _mesAnswer;
  wxTextCtrl *_textArea;
  wxButton* _saveBtn;
  string _filePath;
  wxTreeItemId _updateItemSizeId;
  wxTreeEvent _selectEvent;
};

BEGIN_EVENT_TABLE(TreeFrame, wxFrame)
  EVT_TREE_END_LABEL_EDIT (wxID_ANY, TreeFrame::OnEdit)
  EVT_TREE_ITEM_ACTIVATED(wxID_ANY,TreeFrame::DClick)
  EVT_TREE_SEL_CHANGED(wxID_ANY,TreeFrame::read_file_item_onClick)
  EVT_TREE_BEGIN_LABEL_EDIT(wxID_ANY,TreeFrame::test)
  EVT_BUTTON(wxID_ANY, TreeFrame::saveBtnFunc)
  // EVT_TREE_ITEM_RIGHT_CLICK( wxID_ANY,TreeFrame::toggle_item_onClick )
END_EVENT_TABLE()
#endif
