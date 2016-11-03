#include "SleepKillThread.h"

SleepKillThread::SleepKillThread(workspace_switcherFrame *frame)
{
    this->Sleep(2000);
    //wxThread::Sleep(2000);
    frame->terMenate();
    this->OnExit();
    //&frame->Destory();
    //myMaster=frame;
    //frame->Destory();
}

SleepKillThread::~SleepKillThread()
{
    //dtor
}

void* SleepKillThread::Entry()
{
  return NULL;
}

void SleepKillThread::OnExit()
{
    //&myMaster->Destory();
}
