//
// ScopedLock.cpp for hh in /home/nuts/local/ZIA/src/thread/linux
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Fri Jan 25 16:19:32 2013 Rivot Corentin
// Last update Fri Feb  8 10:59:26 2013 Antoine Rozo
//


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
