//
// ScopedLock.cpp for hh in /home/nuts/local/ZIA/src/thread/linux
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Fri Jan 25 16:19:32 2013 Rivot Corentin
// Last update Fri Jan 25 16:19:44 2013 Rivot Corentin
//


#include "ScopedLock.hpp"

ScopedLock::ScopedLock()
{
  _mutex.lock();
}

ScopedLock::~ScopedLock()
{
  _mutex.unlock();
}

