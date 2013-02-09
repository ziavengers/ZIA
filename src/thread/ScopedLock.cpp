#include "thread/ScopedLock.hh"

namespace zia
{
namespace thread
{

ScopedLock::ScopedLock()
{
  _mutex.lock();
}

ScopedLock::~ScopedLock()
{
  _mutex.unlock();
}

  Locker::Locker(Mutex* m)
  {
    _mutex = m;
    _mutex->lock();
  }

  Locker::~Locker()
  {
    _mutex->unlock();
  }

}
}
