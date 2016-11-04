/***************************************************************
 * Name:      workspace_switcherMain.cpp
 * Purpose:   Code for Application Frame
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

#include "workspace_switcherMain.h"
#include "wx/dcclient.h"
#include "image/workspace-1.h"
#include "image/workspace-2.h"
#include "image/workspace-3.h"
#include "image/workspace-4.h"
#include "image/workspace-5.h"
#include "image/workspace-6.h"
#include "image/workspace-7.h"
#include "image/workspace-8.h"

workspace_switcherFrame::workspace_switcherFrame(wxFrame *frame, long myDesktopi)
: GUIFrame(frame)
{
    wxImage::AddHandler(new wxPNGHandler);

    //1920x1080
    wxPoint* abc = new wxPoint(870,510);

    //1360x768
    //wxPoint* abc = new wxPoint(590,354);

    this->Move(*abc);

    if(myDesktopi==0){
        workf = wxBITMAP_PNG_FROM_DATA(work1);
    }else if(myDesktopi==1){
        workf = wxBITMAP_PNG_FROM_DATA(work2);
    }else if(myDesktopi==2){
        workf = wxBITMAP_PNG_FROM_DATA(work3);
    }else if(myDesktopi==3){
        workf = wxBITMAP_PNG_FROM_DATA(work4);
    }else if(myDesktopi==4){
        workf = wxBITMAP_PNG_FROM_DATA(work5);
    }else if(myDesktopi==5){
        workf = wxBITMAP_PNG_FROM_DATA(work6);
    }else if(myDesktopi==6){
        workf = wxBITMAP_PNG_FROM_DATA(work7);
    }else if(myDesktopi==7){
        workf = wxBITMAP_PNG_FROM_DATA(work8);
    }else{
        return;
    }

    myRegion = new wxRegion(workf, *wxBLACK);
    wxPaintDC dc(this);
    this->SetShape(*myRegion);
    dc.DrawBitmap(workf, 0, 0, true);
    this->Show();

    wxTimer* m_pTimer = new wxTimer(this,TIMER_ID);
    this->Connect( m_pTimer->GetId(),wxEVT_TIMER, wxTimerEventHandler( workspace_switcherFrame::OnTimerTimeout ),NULL, this );
	m_pTimer->Start(350);
}

workspace_switcherFrame::~workspace_switcherFrame()
{
}

void workspace_switcherFrame::OnPaint( wxPaintEvent& event ){
    wxPaintDC dc(this);
    this->SetShape(*myRegion);
    dc.DrawBitmap(workf, 0, 0, true);
}

void workspace_switcherFrame::OnTimerTimeout(wxTimerEvent& event)
{
    this->Destroy();
}
