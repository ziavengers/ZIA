#include "thread/CondVar.hh"

namespace zia
{
  namespace thread
  {

    CondVar::CondVar()
    {
      pthread_mutex_init(&_mutex, NULL);
      pthread_cond_init(&_cond, NULL);
    }

    void    CondVar::wait()
    {
      pthread_mutex_lock(&_mutex);
      pthread_cond_wait(&_cond, &_mutex);
      pthread_mutex_unlock(&_mutex);
    }
    bool CondVar::timedWait(int time)
    {
      struct timeval tv;
      struct timespec ts;
      int   ret;
      gettimeofday(&tv, NULL);
      ts.tv_sec = tv.tv_sec + time;
      ts.tv_nsec = time;
      ret = pthread_cond_timedwait(&_cond, &_mutex, &ts);
      return (ret == 0);
    }
    void    CondVar::signal()
    {
      pthread_cond_signal(&_cond);
    }

    void    CondVar::broadcast()
    {
      pthread_cond_broadcast(&_cond);
    }
  }
}
