#ifndef TREE_FRAME_H
#define TREE_FRAME_H

#include <wx/treectrl.h>

class TreeFrame : public wxFrame
{
public:
  TreeFrame(const wxChar *title, int xpos, int ypos, int width, int height):wxFrame((wxFrame *) nullptr, -1, title, wxPoint(xpos, ypos), wxSize(width, height))
  {
    _tree = new wxTreeCtrl(this, wxID_ANY, wxPoint(0,0), wxSize(100,200), wxTR_DEFAULT_STYLE | wxTR_SINGLE | wxTR_EDIT_LABELS );

    wxTreeItemId rootId = _tree->AddRoot(wxT("Root"));
    wxTreeItemId folder1Id = _tree->AppendItem(rootId, wxT("Folder1"));
    wxTreeItemId file1Id = _tree->AppendItem(folder1Id, wxT("File1"));
    wxTreeItemId file2Id = _tree->AppendItem(rootId, wxT("File2"));
    _tree->ExpandAllChildren(rootId);
  }

void OnEdit(wxTreeEvent& event)
{
  std::cout << "edited" << std::endl;
}

  wxTreeCtrl *_tree;
private:
  DECLARE_EVENT_TABLE()

};

BEGIN_EVENT_TABLE(TreeFrame, wxFrame)
  EVT_TREE_END_LABEL_EDIT (wxID_ANY, TreeFrame::OnEdit)
END_EVENT_TABLE()
#endif
