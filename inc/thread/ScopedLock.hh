//
// ScopedLock.hh for hh in /home/nuts/local/ZIA/src/thread/linux
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Fri Jan 25 16:19:18 2013 Rivot Corentin
// Last update Fri Feb  8 15:13:07 2013 Rivot Corentin
//

#ifndef SCOPEDLOCK_HPP_
#define SCOPEDLOCK_HPP_

#include "thread/Mutex.hh"

namespace zia
{
  namespace thread
  {

    class	ScopedLock
    {
    public:
      ScopedLock();
      ~ScopedLock();

    private:
      Mutex	_mutex;
    };

    class Locker
    {
    public:
      explicit Locker(Mutex*);
      ~Locker();

    private:
      Mutex	*_mutex;
    };

  }
}

#endif
