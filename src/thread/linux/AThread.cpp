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

