#ifndef ATHREAD_HH_
#define ATHREAD_HH_

#ifdef WIN


#pragma once

#include <windows.h>

typedef HANDLE	thread_t

#endif

#ifdef LIN

#include <pthread.h>

#define __delspec()

typedef pthread_t	thread_t

#endif


namespace zia
{
  namespace thread
  {

    class __declspec(dllexport) AThread
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
