#ifndef MUTEX_HPP_
#define MUTEX_HPP_

#include <pthread.h>
#include "IMutex.hh"

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
