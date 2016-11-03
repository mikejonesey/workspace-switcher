/***************************************************************
 * Name:      workspace_switcherApp.h
 * Purpose:   Defines Application Class
 * Author:    Michael Jones (michael.jones@linux.com)
 * Created:   2012-11-18
 * Copyright: Michael Jones (http://www.mikejonesey.co.uk/)
 * License:
 **************************************************************/

#ifndef WORKSPACE_SWITCHERAPP_H
#define WORKSPACE_SWITCHERAPP_H

#include "workspace_switcherMain.h"

#include <wx/app.h>
#include <wx/msgdlg.h>

class workspace_switcherApp : public wxApp
{
    public:
        virtual bool OnInit();
    private:
        virtual int OnExit() wxOVERRIDE;

};

#endif // WORKSPACE_SWITCHERAPP_H
