//
// AThread.cpp for hh in /home/nuts/local/ZIA/src/thread/linux
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Fri Jan 25 16:12:43 2013 Rivot Corentin
// Last update Fri Feb  8 10:59:46 2013 Antoine Rozo
//

#include "thread/linux/AThread.hh"

void	AThread::start()
{
  if (pthread_create(&_thread, 0, &AThread::startRoutine, this) != 0)
    ;//    throw CoreException("AThread::start fail!");
}

void*	AThread::join()
{
  void*	ret;

  if (pthread_join(_thread, &ret) != 0)
    ;//    throw CoreException("AThread::join fail!");
  return ret;
}

void*	AThread::startRoutine(void* data)
{
  AThread*	t;

  t = reinterpret_cast< AThread* >(data);
  return t->run();
}

