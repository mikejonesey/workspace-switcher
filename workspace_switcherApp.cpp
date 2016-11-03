/***************************************************************
 * Name:      workspace_switcherApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Michael Jones (michael.jones@linux.com)
 * Created:   2012-11-18
 * Copyright: Michael Jones (http://www.mikejonesey.co.uk/)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "workspace_switcherApp.h"
#include "workspace_switcherMain.h"

IMPLEMENT_APP(workspace_switcherApp);

bool workspace_switcherApp::OnInit()
{
    size_t argc = workspace_switcherApp::argc;
    wxString myDesktop;
    long myDesktopi;
    wxArrayString* output = new wxArrayString;
    wxExecute(_("wmctrl -d"), *output, 0);
    size_t outputSize = output->GetCount();
    wxString testString;
    for(size_t ii=0;ii<outputSize;ii++){
        testString = output->Item(ii);
        if(testString.Contains(_("*"))){
            myDesktop=testString.Left(1);
            myDesktop.ToLong(&myDesktopi);
            //wxMessageBox(myDesktop,_("test"));
        }
    }
    if(argc>0){
        //get chnage mode
        wxString myMode = workspace_switcherApp::argv[1];
        wxString switchCmd=_("wmctrl -s ");
        if(myMode.Cmp(_("left"))==0){
            if(myDesktopi!=0&&myDesktopi!=4){
                myDesktopi=myDesktopi-1;
            }
        }else if(myMode.Cmp(_("right"))==0){
            if(myDesktopi!=3&&myDesktopi!=7){
                myDesktopi=myDesktopi+1;
            }
        }else if(myMode.Cmp(_("up"))==0){
            if(myDesktopi>3){
                myDesktopi=myDesktopi-4;
            }
        }else if(myMode.Cmp(_("down"))==0){
            if(myDesktopi<4){
                myDesktopi=myDesktopi+4;
            }
        }else if(myMode.IsNumber()){
            myMode.ToLong(&myDesktopi);
            myDesktopi=myDesktopi-1;
        }
        if(myDesktopi>-1&&myDesktopi<8){
            switchCmd << myDesktopi;
            wxExecute(switchCmd);
        }else{
            myDesktopi=0;
        }
    }
    workspace_switcherFrame* myPopUp = new workspace_switcherFrame(0L,myDesktopi);
    myPopUp->Show();
    return true;
}

int workspace_switcherApp::OnExit(){
    return 0;
}
