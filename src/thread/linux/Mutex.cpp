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
