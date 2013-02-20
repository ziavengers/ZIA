#ifndef ITHREAD_HH_
#define ITHREAD_HH_

namespace zia
{
  namespace thread
  {

    class IThread
    {
    public:
      virtual void statrt() = 0;
      virtual void* join() = 0;

      virtual void init(void*) = 0;
      virtual void* run() = 0;
      virtual void pause() = 0;
      virtual void resume() = 0;
    };

  }
}

#endif
