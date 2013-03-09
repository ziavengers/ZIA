#ifndef THREAD_ICONDVAR_HH_
#define THREAD_ICONDVAR_HH_

namespace zia
{
  namespace thread
  {

    class ICondVar
    {
    public:
      virtual void wait() = 0;
      virtual bool timedWait(int) = 0;
      virtual void signal() = 0;
      virtual void broadcast() = 0;
    };

  }
}

#endif
