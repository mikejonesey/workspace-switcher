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

class workspace_switcherFrame: public GUIFrame
{
    public:
        workspace_switcherFrame(wxFrame *frame, long myDesktopi);
        ~workspace_switcherFrame();
        long setmyDesktopi;
        wxBitmap workf;
        wxRegion* myRegion;
        virtual void OnTimerTimeout(wxTimerEvent& event);
    private:
        virtual void OnPaint( wxPaintEvent& event );
};

#endif // WORKSPACE_SWITCHERMAIN_H
