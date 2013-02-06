//
// ScopedLock.cpp for hh in /home/nuts/local/ZIA/src/thread/linux
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Fri Jan 25 16:19:32 2013 Rivot Corentin
// Last update Wed Feb  6 10:45:47 2013 Rivot Corentin
//


#include "ScopedLock.hh"

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
