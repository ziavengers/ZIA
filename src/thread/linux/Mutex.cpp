//
// Mutex.cpp for hh in /home/nuts/local/ZIA/src/thread/linux
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Fri Jan 25 16:18:21 2013 Rivot Corentin
// Last update Fri Feb  8 10:59:42 2013 Antoine Rozo
//

#include "thread/linux/Mutex.hh"


namespace zia
{

namespace thread
{


Mutex::Mutex()
{
  pthread_mutex_init(&_mutex, 0);
}

Mutex::~Mutex()
{
  pthread_mutex_destroy(&_mutex);
}

void	Mutex::lock()
{
  if (pthread_mutex_lock(&_mutex) != 0)
    ;//throw CoreException("Mutex::lock fail");
}

void	Mutex::unlock()
{
  if (pthread_mutex_unlock(&_mutex) != 0)
    ;//throw CoreException("Mutex::unlock fail");
}

bool	Mutex::trylock()
{
  if (pthread_mutex_trylock(&_mutex) == 0)
    return true;
  return false;
}


}
}
