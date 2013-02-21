#include "core/ThreadPool.hh"

#include <iostream>
#include <unistd.h>
int iii = 0;

namespace zia
{
  namespace core
  {

    ThreadPool::Thread::Thread(ThreadPool& pool) : _pool(pool)
    {}
    ThreadPool::Thread::Thread(const Thread& other) : _pool(other._pool)
    {}
    void ThreadPool::Thread::init(void*)
    {}
    void* ThreadPool::Thread::run()
    {
      int i = iii++;
      while (1)
	{
	  std::cout << i << std::endl;
	  usleep(500000);
	}
      return 0;
    }
    void ThreadPool::Thread::pause()
    {}
    void ThreadPool::Thread::resume()
    {}

    ThreadPool::ThreadPool(unsigned int nb) : _threads(nb, Thread(*this))
    {}
    void ThreadPool::start()
    {
      std::vector< Thread >::iterator it;
      for (it = _threads.begin(); it != _threads.end(); ++it)
	it->start();
    }
  }
}

int main()
{
  zia::core::ThreadPool pool(5);
  pool.start();
  while (1)
    ;
}
