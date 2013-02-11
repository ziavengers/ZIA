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
      explicit Locker(IMutex*);
      ~Locker();

    private:
      IMutex	*_mutex;
    };

  }
}

#endif
