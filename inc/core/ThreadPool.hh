#ifndef THREADPOOL_HH_
#define THREADPOOL_HH_

#include <vector>
#include "thread/AThread.hh"

namespace zia
{
  namespace core
  {

    class ThreadPool
    {
    private:
      class Thread : public thread::AThread
      {
      public:
	Thread(ThreadPool&);
	Thread(const Thread&);
	void init(void*);
	void* run();
	void pause();
	void resume();
      private:
	ThreadPool& _pool;
      };

    public:
      ThreadPool(unsigned int);
      void start();

    private:
      std::vector< Thread > _threads;
    };

  }
}

#endif
