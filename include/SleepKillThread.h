#ifndef SLEEPKILLTHREAD_H
#define SLEEPKILLTHREAD_H

#include "../workspace_switcherMain.h"

class SleepKillThread : public wxThread
{
    public:
        SleepKillThread(workspace_switcherFrame *frame);
        virtual ~SleepKillThread();
        // thread execution starts here
        virtual void *Entry() wxOVERRIDE;
        // called when the thread exits - whether it terminates normally or is
        // stopped with Delete() (but not when it is Kill()ed!)
        virtual void OnExit() wxOVERRIDE;
        workspace_switcherFrame *myMaster;
    protected:

    private:
};

#endif // SLEEPKILLTHREAD_H
