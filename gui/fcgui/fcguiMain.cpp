/***************************************************************
 * Name:      fcguiMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Theron Spiegl (tspiegl@gmail.com)
 * Created:   2018-12-26
 * Copyright: Theron Spiegl ()
 * License:
 **************************************************************/

#include "fcguiMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(fcguiDialog)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(fcguiDialog)
const long fcguiDialog::ID_STATICTEXT1 = wxNewId();
const long fcguiDialog::ID_BUTTON1 = wxNewId();
const long fcguiDialog::ID_STATICLINE1 = wxNewId();
const long fcguiDialog::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(fcguiDialog,wxDialog)
    //(*EventTable(fcguiDialog)
    //*)
END_EVENT_TABLE()

fcguiDialog::fcguiDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(fcguiDialog)
    Create(parent, id, _("wxWidgets app"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Welcome to\nwxWidgets"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    if ( !StaticText1Font.Ok() ) StaticText1Font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    StaticText1Font.SetPointSize(20);
    StaticText1->SetFont(StaticText1Font);
    BoxSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    Button1 = new wxButton(this, ID_BUTTON1, _("About"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    BoxSizer2->Add(StaticLine1, 0, wxALL|wxEXPAND, 4);
    Button2 = new wxButton(this, ID_BUTTON2, _("Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer1->Add(BoxSizer2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&fcguiDialog::OnAbout);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&fcguiDialog::OnQuit);
    //*)
}

fcguiDialog::~fcguiDialog()
{
    //(*Destroy(fcguiDialog)
    //*)
}

void fcguiDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void fcguiDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
