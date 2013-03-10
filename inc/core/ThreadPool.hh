#ifndef CORE_THREADPOOL_HH_
#define CORE_THREADPOOL_HH_

#include <vector>
#include <queue>
#include <string>
#include "thread/AThread.hh"
#include "thread/CondVar.hh"
#include "thread/Mutex.hh"
#include "utils/bind.hpp"

namespace zia
{
  namespace core
  {
    class Object;

    class ThreadPool
    {
    private:
      class Thread : public thread::AThread
      {
      public:
	Thread(ThreadPool&);
	Thread(const Thread&);
	void* run();
      private:
	ThreadPool& _pool;
      };

      struct s_event
      {
	s_event(Object* s_, Object* r_, const std::string& context_, const utils::StockCallback& c_):
	  sender(s_), receiver(r_), context(context_), c(c_)
	{}
	Object* sender;
	Object* receiver;
	std::string context;
	utils::StockCallback c;
      };

    public:
      ThreadPool(unsigned int = 1);
      void start();
      void push(Object*, Object*, const std::string&, const utils::StockCallback&);
      s_event pop();

      // void wait(int = 1);

    private:
      std::vector< Thread > _threads;
      std::queue< s_event > _events;
      thread::CondVar _eventsCond;
      thread::Mutex _eventsMutex;
    };

  }
}

#endif
