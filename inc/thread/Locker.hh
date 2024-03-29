#ifndef THREAD_LOCKER_HH_
#define THREAD_LOCKER_HH_

#include "thread/Mutex.hh"

namespace zia
{
  namespace thread
  {

    class Locker
    {
    public:
      explicit Locker(IMutex&);
      ~Locker();

    private:
      IMutex	&_mutex;
    };    

  }
}

#endif
