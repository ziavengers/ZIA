#include "inc/windows/Mutex.h"


Mutex::Mutex(void)
{
  if ((_mutex = CreateMutex(NULL, FALSE, NULL)) == NULL)
    ;//throw CoreException("Mutex::Constructor fail");
}


Mutex::~Mutex(void)
{
  if (CloseHandle(_mutex) == 0)
    ;//throw CoreException("Mutex::Destructor fail");
}

void	Mutex::lock(void)
{
  switch (WaitForSingleObject(_mutex, INFINITE))
    {
    case WAIT_ABANDONED :
      ;//throw CoreException("Mutex::lock fail, abandoned");
      //case WAIT_OBJECT_0 :
    case WAIT_TIMEOUT :
      ;//throw CoreException("Mutex::lock fail, timeout");
    case WAIT_FAILED :
      ;//throw CoreException("Mutex::lock fail");
    }
}

void	Mutex::unlock(void)
{
  if (ReleaseMutex(_mutex) == 0)
    ;//throw CoreException("Mutex::unlock fail");
}

bool	Mutex::trylock(void)
{
  switch (WaitForSingleObject(_mutex, INFINITE))
    {
    case WAIT_ABANDONED :
      ;//throw CoreException("Mutex::lock fail, abandoned");
    case WAIT_OBJECT_0 :
      return true;
    case WAIT_TIMEOUT :
      ;//throw CoreException("Mutex::lock fail, timeout");
    case WAIT_FAILED :
      ;//throw CoreException("Mutex::lock fail");
    }
  return false;
}
