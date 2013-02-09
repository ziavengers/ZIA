#ifndef MUTEX_HPP_
#define MUTEX_HPP_

#include <pthread.h>

namespace zia
{
  namespace thread
  {

    class Mutex
    {
    public:
      Mutex();
      ~Mutex();

      void	lock();
      void	unlock();
      bool	trylock();

    private:
      pthread_mutex_t	_mutex;
    };

  }
}

#endif
