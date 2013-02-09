//
// Mutex.hh for hh in /home/nuts/local/ZIA/src/thread/linux
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Fri Jan 25 16:17:55 2013 Rivot Corentin
// Last update Fri Feb  8 14:23:54 2013 Rivot Corentin
//


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
