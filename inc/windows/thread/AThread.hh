#ifndef THREAD_ATHREAD_HH_
#define THREAD_ATHREAD_HH_

#pragma once

#include <windows.h>
#include "thread/IThread.hh"

namespace zia
{
  namespace thread
  {

    class __declspec(dllexport) AThread : public IThread
    {
    public:
      void		start();
      void*		join();

      virtual void	init(void*) = 0;
      virtual void*	run() = 0;
      virtual void	pause() = 0;
      virtual void	resume() = 0;

    protected:
      HANDLE	_thread;

    private:
      static void*	startRoutine(LPVOID);
    };
  }
}

#endif
