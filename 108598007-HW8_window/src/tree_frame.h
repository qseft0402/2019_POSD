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

  TreeFrame(const wxChar *title,wxString rootPath, int xpos, int ypos, int width, int height):wxFrame((wxFrame *) nullptr, -1, title, wxPoint(xpos, ypos), wxSize(width, height)),_selcetNode(_root)
  {

    wxPanel* panel = new wxPanel(this, wxID_ANY);
    Node* root;
    _tree = new wxTreeCtrl(this, wxID_ANY, wxPoint(xpos,ypos), wxSize(width,height), wxTR_HAS_BUTTONS  | wxTR_SINGLE );
    root=SetFileSystem(string(rootPath.mb_str()));

    _root=root;
    _selcetNode=root;
     Folder * folder = dynamic_cast<Folder *> (root);

    // cout<<"count!: "<<folder->getChild("ffff")->getPath()<<endl;
    updateTree(folder);
    cout<<"here2"<<endl;

    _textArea=new wxTextCtrl(_tree, -1, _T("you can choice file to show in textbox..."),
		wxPoint(170,0),  wxSize(700,500), wxTE_MULTILINE);
    _textArea->Enable(false);
    // _textArea->Connect(wxEVT_KEY_DOWN,wxKeyEventHandler(TreeFrame::KeyDownEvent1),NULL,this);
    _saveBtn=new wxButton(this,BUTTON_Hello,_T("Save"),wxPoint(170,510),wxSize(700,100),0);
    _saveBtn->Enable(false);
    cout<<"here3"<<endl;

    // wxAcceleratorEntry entries[1];
    // entries[0].Set(wxACCEL_CTRL,WXK_RETURN);
    // wxAcceleratorTable accel(1,entries);
    // _textArea->SetAcceleratorTable(accel);
    _textArea->Bind(wxEVT_KEY_DOWN ,wxKeyEventHandler(TreeFrame::KeyDownEvent),this);
    _textArea->Bind(wxEVT_KEY_UP ,wxKeyEventHandler(TreeFrame::KeyUpEvent),this);

    _tree->Bind(wxEVT_KEY_DOWN  ,wxKeyEventHandler(TreeFrame::KeyDownEvent), this);
    _tree->Bind(wxEVT_KEY_UP ,wxKeyEventHandler(TreeFrame::KeyUpEvent),this);

  }
void KeyUpEvent(wxKeyEvent& event){
  cout<<"keyUPEvent"<<endl;

  keyBordTemp.clear();
  event.Skip();
}

void KeyDownEvent(wxKeyEvent& event){

  if(_selcetNode->getType()==1){
    if(keyBordTemp.size()>1) keyBordTemp.clear();
    keyBordTemp.push_back(event.GetKeyCode());
    if(keyBordTemp.at(0)==308){
      cout<<"press ctrl"<<endl;
      if(keyBordTemp.size()==1){
        return;
      }
      if(keyBordTemp.at(1)==83){
        cout<<"press s"<<endl;
        saveFile();
      }
    }
    else{
      keyBordTemp.clear();
      event.Skip();
    }
  }
  else{
    event.Skip();
  }
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


Node* _selcetNode;
  void read_file_item_onClick(wxTreeEvent &event)
{

    wxTreeItemId itemId = event.GetItem();
    _updateItemSizeId=itemId;
    std::cout << itemId<< std::endl;
    // cout<<"going to find "<<itemId<<endl;
    Node* node=getNodeById(itemId,_root);
    _selcetNode=node;
    // cout<<" id= "<<itemId<<endl;
    _filePath=node->getPath();
    if(!node) cout<<"NULLPTR"<<endl;
    else{
      if(node->getType()==1){
          _textArea->Enable(true);
          _saveBtn->Enable(true);

        // cout<<"onclick:"<<node->getPath()<<endl;
        // cout<<"here2"<<endl;
        _textArea->LoadFile(wxT_2(node->getPath()));
      }
      else if(node->getType()==3){
          _textArea->ChangeValue(wxT_2("The file is not displayed in the editor because it uses an unsupported text encoding."));
          _textArea->Enable(false);
          _saveBtn->Enable(false);

          // _textArea->Refresh();
      }
      else if(node->getType()==2){
          _textArea->ChangeValue(wxT_2("This is a folder can't show anything"));
          _textArea->Enable(false);
          _saveBtn->Enable(false);

          // _textArea->Refresh();
      }
    }

}

void updateTree(Node* root){
    Iterator* it=root->createIterator();
    // cout<<"updateTree root="<<root->getPath()<<endl;
    wxTreeItemId rootId = _tree->AddRoot(wxT_2(root->name()+", "+to_string(root->getSize())));
    root->setWxTreeItemId(rootId);
    for(it->first();!it->isDone();it->next()){
      Node* node=it->currentItem();
      if(node->getType()!=2){
        // cout<<"build!! "<<node->getPath()<<endl;
        wxTreeItemId id=_tree->AppendItem(rootId, wxT_2(node->name()+", "+to_string(node->getSize())));
        node->setWxTreeItemId(id);
        // cout<<"build!! id="<<node->getWxTreeItemId()<<endl;


      }else{
        wxTreeItemId id=_tree->AppendItem(rootId, wxT_2(node->name()+", "+to_string(node->getSize())));
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

        wxTreeItemId id =_tree->AppendItem(pid, wxT_2(node->name()+", "+to_string(node->getSize())));
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
bool ShowMessageRename(string newName,string oldName)
{
  wxMessageDialog *dial= new wxMessageDialog(NULL,
      wxT("label edited: "+newName+"-- old name was "+oldName), wxT("Confirm"),
      wxYES_NO | wxCANCEL | wxNO_DEFAULT | wxICON_QUESTION);
      return MessageIsSave(dial);

}
bool ShowMessageSave()
{
  wxMessageDialog *dial= new wxMessageDialog(NULL,
      wxT("You want save?"), wxT("Confirm"),
      wxYES_NO | wxCANCEL | wxNO_DEFAULT | wxICON_QUESTION);
      return MessageIsSave(dial);
}
bool MessageIsSave(wxMessageDialog *dial){
  if(dial->ShowModal()==wxID_YES) return true;
  else return false;

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
      bool resultFeedBack=ShowMessageRename(newName,oldName);
      if(resultFeedBack){
        cout<<"resultFeedBack Yes!!"<<endl;

      }else{
        _tree->SetItemText(itemId,wxString(oldName+", "+to_string(node->getSize())));
        event.Veto();
        return;
      }
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
  Node* targetNode=nullptr;
  cout<<"target id :"<<id<<endl;
  if(root->getWxTreeItemId()==id){
    targetNode=root;
  }
  Folder * folder = dynamic_cast<Folder *> (root);
  if(folder!=nullptr){
    Iterator* it=folder->createIterator();
    for(it->first();!it->isDone();it->next()){
      Node* node=it->currentItem();
      cout<<"current id :"<<node->getWxTreeItemId()<<endl;
      if(node->getWxTreeItemId()==id){
        cout<<"retrun !!"<<node->name()<<endl;
        targetNode=node;
      }
      if(node->getType()==2){
        subgetNodeById(id,node,targetNode);
      }
    }
  }
return targetNode;
}

void subgetNodeById(wxTreeItemId id,Node* root,Node* &targetNode){
  Iterator* it=root->createIterator();
  for(it->first();!it->isDone();it->next()){
    Node* node=it->currentItem();
    cout<<"current id :"<<node->getWxTreeItemId()<<endl;
    if(node->getWxTreeItemId()==id){
      cout<<"retrun !!"<<node->name()<<endl;
      targetNode=node;
    }
    if(node->getType()==2){
      subgetNodeById(id,node,targetNode);
    }
  }
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
  saveFile();
}
void saveFile(){
  Node* node=getNodeById(_updateItemSizeId,_root);
  if(node->getType()==1){
    bool resultFeedBack=ShowMessageSave();
    if(resultFeedBack){
      cout<<"going to save " <<_filePath<<endl;
    }
    else{

      return ;
    }
  }
  cout<<_textArea->GetLineText(0)<<endl;
  cout<<_textArea->GetNumberOfLines()<<endl;
  _textArea->SaveFile(wxT_2(_filePath));

  updataItemSize(_updateItemSizeId,node);

}

void DialogFeedback(wxInitDialogEvent&  event){
  cout<<"DialogFeedback"<<endl;
}
  wxTreeCtrl *_tree;
private:
  DECLARE_EVENT_TABLE()
  bool _run;
  Node* _root;
  int _mesAnswer;
  wxTextCtrl *_textArea;
  wxButton* _saveBtn;
  string _filePath;
  wxTreeItemId _updateItemSizeId;
  wxTreeEvent _selectEvent;
  std::vector<int> keyBordTemp;
};

BEGIN_EVENT_TABLE(TreeFrame, wxFrame)
  EVT_TREE_END_LABEL_EDIT (wxID_ANY, TreeFrame::OnEdit)
  EVT_TREE_ITEM_ACTIVATED(wxID_ANY,TreeFrame::DClick)
  EVT_TREE_SEL_CHANGED(wxID_ANY,TreeFrame::read_file_item_onClick)
  EVT_TREE_BEGIN_LABEL_EDIT(wxID_ANY,TreeFrame::test)
  EVT_BUTTON(wxID_ANY, TreeFrame::saveBtnFunc)
  // EVT_TREE_KEY_DOWN(wxID_ANY,TreeFrame::KeyDownEvent)
  // EVT_TEXT_ENTER(wxID_ANY,TreeFrame::KeyDownEvent1)
  EVT_INIT_DIALOG(TreeFrame::DialogFeedback)
  // EVT_CHAR(TreeFrame::KeyDownEvent1 )

  // EVT_KEY_UP(TreeFrame::KeyDownEvent1)
  // EVT_CHAR_HOOK(TreeFrame::KeyDownEvent1)

  // EVT_TREE_ITEM_RIGHT_CLICK( wxID_ANY,TreeFrame::toggle_item_onClick )
END_EVENT_TABLE()

#endif
