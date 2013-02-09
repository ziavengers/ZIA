#ifndef MUTEX_HH_
#define MUTEX_HH_

#pragma once

#include <Windows.h>

namespace zia
{
  namespace thread
  {

    class __declspec(dllexport) Mutex
    {
    public:
      Mutex();
      ~Mutex();

      void	lock();
      void	unlock();
      bool	trylock();

    private:
      HANDLE	_mutex;
    };

  }
}

#endif

