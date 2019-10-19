#include <wx/wx.h>
#include <wx/treectrl.h>

#include "hello_world.h"
#include "text_frame.h"

IMPLEMENT_APP(HelloWorldApp)

// This is executed upon startup, like 'main()' in non-wxWidgets programs.
bool HelloWorldApp::OnInit()
{
	wxFrame *frame = new TextFrame(wxT("Hello wxWidgets World"), 200, 400, 400, 300);
	frame->Show(true);
	this->SetTopWindow(frame);
	return true;
}
