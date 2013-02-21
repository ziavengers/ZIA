#ifndef ITHREAD_HH_
#define ITHREAD_HH_

namespace zia
{
  namespace thread
  {

    class IThread
    {
    public:
      virtual void start() = 0;
      virtual void* join() = 0;
      virtual void* run() = 0;
    };

  }
}

#endif
