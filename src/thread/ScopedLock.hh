//
// ScopedLock.hh for hh in /home/nuts/local/ZIA/src/thread/linux
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Fri Jan 25 16:19:18 2013 Rivot Corentin
// Last update Fri Jan 25 16:19:23 2013 Rivot Corentin
//

#ifndef SCOPEDLOCK_HPP_
#define SCOPEDLOCK_HPP_

#include "Mutex.hpp"

class	ScopedLock
{
public:
  ScopedLock();
  ~ScopedLock();

private:
  Mutex	_mutex;
};

#endif
