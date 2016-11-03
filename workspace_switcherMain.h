/***************************************************************
 * Name:      workspace_switcherMain.h
 * Purpose:   Defines Application Frame
 * Author:    Michael Jones (michael.jones@linux.com)
 * Created:   2012-11-18
 * Copyright: Michael Jones (http://www.mikejonesey.co.uk/)
 * License:
 **************************************************************/

#ifndef WORKSPACE_SWITCHERMAIN_H
#define WORKSPACE_SWITCHERMAIN_H

#include "workspace_switcherApp.h"

#include "GUIFrame.h"
#include <wx/mstream.h>
#include "wx/image.h"
#include "wx/menu.h"
#include <wx/timer.h>
enum
{
    TIMER_ID= 10
};

//#include <wx/dcmemory.h>

class workspace_switcherFrame: public GUIFrame
{
    public:
        workspace_switcherFrame(wxFrame *frame, long myDesktopi);
        ~workspace_switcherFrame();
        //wxPaintDC *dc;
        long setmyDesktopi;
        wxBitmap workf;
        wxRegion* myRegion;
        virtual void OnTimerTimeout(wxTimerEvent& event);
    private:
        virtual void onActiv( wxActivateEvent& event);
        //virtual void testMoo( wxKeyEvent& event );
        virtual void OnPaint( wxPaintEvent& event );
        virtual void OnIdle( wxIdleEvent& event );
        //wxBitmap workf;
};

#endif // WORKSPACE_SWITCHERMAIN_H
