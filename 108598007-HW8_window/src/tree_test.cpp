#include <wx/wx.h>
#include "tree_test.h"
#include "tree_frame.h"
IMPLEMENT_APP(TreeTestApp)

bool TreeTestApp::OnInit()
{
  try{
  wxString  rootPath(wxGetApp().argv[1]);
  wxFrame *frame = new TreeFrame(wxT("***Tree Test***"), rootPath,0,0,1000,700);
  frame->Show(true);
  this->SetTopWindow(frame);

  // Link* l=new Link("test/fileLink");
  // cout<<"link type"<<l->getType()<<endl;
  }catch(exception e){
    cout<<e.what()<<endl;
  }
  // wxFrame *textFrame =new TextFrame(wxT("textFrame") , 200, 200, 300, 300);
  // textFrame->Show(true);
  // this->SetTopWindow(textFrame);
  return true;
}
