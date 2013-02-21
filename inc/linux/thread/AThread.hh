#ifndef ATHREAD_HH_
#define ATHREAD_HH_

#include <pthread.h>
#include "thread/IThread.hh"

namespace zia
{
  namespace thread
  {

    class AThread : public IThread
    {
    public:
      void		start();
      void*		join();
      void		cancel();

      virtual void*	run() = 0;

    protected:
      pthread_t	_thread;

    private:
      static void*	startRoutine(void*);
    };

  }
}

#endif
