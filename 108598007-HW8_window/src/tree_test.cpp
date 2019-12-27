#include <wx/wx.h>
#include "tree_test.h"
#include "tree_frame.h"

IMPLEMENT_APP(TreeTestApp)

bool TreeTestApp::OnInit()
{
  wxFrame *frame = new TreeFrame(wxT("***Tree Test***"), 100,100,1000,700);
  frame->Show(true);
  this->SetTopWindow(frame);
  // wxFrame *textFrame =new TextFrame(wxT("textFrame") , 200, 200, 300, 300);
  // textFrame->Show(true);
  // this->SetTopWindow(textFrame);
  return true;
}
