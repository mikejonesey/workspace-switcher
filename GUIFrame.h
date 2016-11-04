///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIFrame__
#define __GUIFrame__

#include <wx/string.h>
#include <wx/frame.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class GUIFrame
///////////////////////////////////////////////////////////////////////////////
class GUIFrame : public wxFrame
{
	private:

	protected:

		// Virtual event handlers, overide them in your derived class
		virtual void onActiv( wxActivateEvent& event ) { event.Skip(); }
		virtual void testMoo( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnPaint( wxPaintEvent& event ) { event.Skip(); }
        virtual void OnIdle( wxShowEvent& event ) { event.Skip(); }

	public:

		GUIFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Workspace Switcher"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 195,95 ), long style = wxFRAME_NO_TASKBAR|wxFRAME_SHAPED|wxNO_BORDER );
		~GUIFrame();

};

#endif //__GUIFrame__
