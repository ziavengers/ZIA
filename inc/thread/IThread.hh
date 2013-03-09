#ifndef THREAD_ITHREAD_HH_
#define THREAD_ITHREAD_HH_

#include "utils/Exception.hpp"

namespace zia
{
  namespace thread
  {

    class IThread
    {
    public:
      virtual void start() = 0;
      virtual void* join() = 0;
      virtual void cancel() = 0;

      virtual void* run() = 0;

      CLASS_EXCEPTION("zia::thread::IThread: ");
    };

  }
}

#endif
