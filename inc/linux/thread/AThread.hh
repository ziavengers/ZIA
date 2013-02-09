#ifndef ATHREAD_HPP_
#define ATHREAD_HPP_

#include <pthread.h>

namespace zia
{
  namespace thread
  {

    class AThread
    {
    public:
      void		start();
      void*		join();

      virtual void	init(void*) = 0;
      virtual void*	run() = 0;
      virtual void	pause() = 0;
      virtual void	resume() = 0;

    protected:
      pthread_t	_thread;

    private:
      static void*	startRoutine(void*);
    };

  }
}

#endif
