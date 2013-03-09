#ifndef THREAD_MUTEX_HH_
#define THREAD_MUTEX_HH_

#include <pthread.h>
#include "thread/IMutex.hh"

namespace zia
{
  namespace thread
  {

    class Mutex : public IMutex
    {
    public:
      Mutex();
      virtual ~Mutex();

      void	lock();
      void	unlock();
      bool	trylock();

    private:
      pthread_mutex_t	_mutex;
    };

  }
}

#endif
