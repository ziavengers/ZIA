#include "core/ThreadPool.hh"
#include "core/Object.hpp"
#include "thread/Locker.hh"

namespace zia
{
  namespace core
  {

    ThreadPool::Thread::Thread(ThreadPool& pool) : _pool(pool)
    {}
    ThreadPool::Thread::Thread(const Thread& other) : _pool(other._pool)
    {}
    void* ThreadPool::Thread::run()
    {
      while (1)
	{
	  s_event e = _pool.pop();
	  e.receiver->manageSlot(e.sender, e.c);
	}
      return 0;
    }

    ThreadPool::ThreadPool(unsigned int nb) : _threads(nb, Thread(*this)), _events(), _eventsCond(), _eventsMutex()
    {}
    void ThreadPool::start()
    {
      std::vector< Thread >::iterator it;
      for (it = _threads.begin(); it != _threads.end(); ++it)
	it->start();
    }
    void ThreadPool::push(Object* sender, Object* receiver, const utils::StockCallback& c)
    {
      thread::Locker lock(_eventsMutex);
      _events.push(s_event(sender, receiver, c));
      _eventsCond.signal();
    }
    ThreadPool::s_event ThreadPool::pop()
    {
      _eventsCond.wait();
      thread::Locker lock(_eventsMutex);
      s_event e = _events.front();
      _events.pop();
      return e;
    }
  }
}
