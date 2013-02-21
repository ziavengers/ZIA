#ifndef CONDVAR_HH_
#define CONDVAR_HH_

#include <pthread.h>
#include <sys/time.h>
#include "thread/ICondVar.hh"

namespace zia
{
  namespace thread
  {

    class CondVar : public ICondVar
    {
    public:
      CondVar();
      void wait();
      bool timedWait(int);
      void signal();
      void broadcast();
    private:
      pthread_mutex_t _mutex;
      pthread_cond_t _cond;
    };

  }
}

#endif
