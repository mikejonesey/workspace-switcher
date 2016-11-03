///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "GUIFrame.h"

///////////////////////////////////////////////////////////////////////////

GUIFrame::GUIFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxColour( 153, 153, 255 ) );


	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_ACTIVATE, wxActivateEventHandler( GUIFrame::onActiv ) );
	this->Connect( wxEVT_KEY_UP, wxKeyEventHandler( GUIFrame::testMoo ) );
	this->Connect( wxEVT_PAINT, wxPaintEventHandler( GUIFrame::OnPaint ) );
	this->Connect( wxEVT_SHOW, wxShowEventHandler( GUIFrame::OnIdle ) );
}

GUIFrame::~GUIFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_ACTIVATE, wxActivateEventHandler( GUIFrame::onActiv ) );
	this->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( GUIFrame::testMoo ) );
	this->Disconnect( wxEVT_PAINT, wxPaintEventHandler( GUIFrame::OnPaint ) );
	this->Disconnect( wxEVT_SHOW, wxShowEventHandler( GUIFrame::OnIdle ) );

}
