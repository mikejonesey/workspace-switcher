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
    setmyDesktopi = myDesktopi;
    wxImage::AddHandler(new wxPNGHandler);
    //top left
    //wxPoint* abc = new wxPoint(0,0);
    //1920x1080
    wxPoint* abc = new wxPoint(870,510);
    //1360x768
    //wxPoint* abc = new wxPoint(590,354);
    this->Move(*abc);


     //wxMemoryInputStream* work_csi;
    if(setmyDesktopi==0){
        //work_csi = new wxMemoryInputStream(work1_png, sizeof(work1_png));
        workf = wxBITMAP_PNG_FROM_DATA(work1);
    }else if(setmyDesktopi==1){
        //work_csi = new wxMemoryInputStream(work2_png, sizeof(work2_png));
        workf = wxBITMAP_PNG_FROM_DATA(work2);
    }else if(setmyDesktopi==2){
        //work_csi = new wxMemoryInputStream(work3_png, sizeof(work3_png));
        workf = wxBITMAP_PNG_FROM_DATA(work3);
    }else if(setmyDesktopi==3){
        //work_csi = new wxMemoryInputStream(work4_png, sizeof(work4_png));
        workf = wxBITMAP_PNG_FROM_DATA(work4);
    }else if(setmyDesktopi==4){
        //work_csi = new wxMemoryInputStream(work5_png, sizeof(work5_png));
        workf = wxBITMAP_PNG_FROM_DATA(work5);
    }else if(setmyDesktopi==5){
        //work_csi = new wxMemoryInputStream(work6_png, sizeof(work6_png));
        workf = wxBITMAP_PNG_FROM_DATA(work6);
    }else if(setmyDesktopi==6){
        //work_csi = new wxMemoryInputStream(work7_png, sizeof(work7_png));
        workf = wxBITMAP_PNG_FROM_DATA(work7);
    }else if(setmyDesktopi==7){
        //work_csi = new wxMemoryInputStream(work8_png, sizeof(work8_png));
        workf = wxBITMAP_PNG_FROM_DATA(work8);
    }else{
        return;
    }
    //work_csi = new wxMemoryInputStream(work8_png, sizeof(work8_png));
    //wxImage workfa(*work_csi, wxBITMAP_TYPE_PNG);
    //workfa.LoadFile(*work_csi, wxBITMAP_TYPE_PNG);

    myRegion = new wxRegion(workf, *wxBLACK);
    wxPaintDC dc(this);
    this->SetShape(*myRegion);
    dc.DrawBitmap(workf, 0, 0, true);
    this->Show();

    wxTimer* m_pTimer = new wxTimer(this,TIMER_ID);
    this->Connect( m_pTimer->GetId(),wxEVT_TIMER, wxTimerEventHandler( workspace_switcherFrame::OnTimerTimeout ),NULL, this );
    //this->Disconnect(wxID_Timer,wxEVT_TIMER,wxTimerEventHandler( workspace_switcherFrame::OnTimerTimeout ), NULL, this );
	m_pTimer->Start(350);

    /*
    wxImage::AddHandler(new wxPNGHandler);
    wxMemoryInputStream* work_csi;
    if(myDesktopi==0){
        work_csi = new wxMemoryInputStream(work1_data, sizeof(work1_data));
    }else if(myDesktopi==1){
        work_csi = new wxMemoryInputStream(work2_data, sizeof(work2_data));
    }else if(myDesktopi==2){
        work_csi = new wxMemoryInputStream(work3_data, sizeof(work3_data));
    }else if(myDesktopi==3){
        work_csi = new wxMemoryInputStream(work4_data, sizeof(work4_data));
    }else if(myDesktopi==4){
        work_csi = new wxMemoryInputStream(work5_data, sizeof(work5_data));
    }else if(myDesktopi==5){
        work_csi = new wxMemoryInputStream(work6_data, sizeof(work6_data));
    }else if(myDesktopi==6){
        work_csi = new wxMemoryInputStream(work7_data, sizeof(work7_data));
    }else if(myDesktopi==7){
        work_csi = new wxMemoryInputStream(work8_data, sizeof(work8_data));
    }else{
        return;
    }
    wxImage workf(*work_csi, wxBITMAP_TYPE_PNG);
    */
}

/*
void workspace_switcherFrame::testMoo( wxKeyEvent& event ){
    this->Lower();
    wxMessageBox(_("test"),_("test"));
}
*/

workspace_switcherFrame::~workspace_switcherFrame()
{
}

void workspace_switcherFrame::onActiv( wxActivateEvent& event ) {
    //wxSleep(1);
    //wxMilliSleep(350);
    //this->Hide();
    //Refresh();
    //this->Destroy();
}

void workspace_switcherFrame::OnPaint( wxPaintEvent& event ){
    wxPaintDC dc(this);
    this->SetShape(*myRegion);
    dc.DrawBitmap(workf, 0, 0, true);
}

void workspace_switcherFrame::OnIdle( wxIdleEvent& event ) {
    //wxMilliSleep(350);
    //this->Hide();
    //this->Destroy();
}

void workspace_switcherFrame::OnTimerTimeout(wxTimerEvent& event)
{
    this->Destroy();
}
