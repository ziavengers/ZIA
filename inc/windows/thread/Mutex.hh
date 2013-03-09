#ifndef THREAD_MUTEX_HH_
#define THREAD_MUTEX_HH_

#pragma once

#include <Windows.h>
#include "IMutex.hh"

namespace zia
{
  namespace thread
  {

    class __declspec(dllexport) Mutex : public IMutex
    {
    public:
      Mutex();
      virtual ~Mutex();

      void	lock();
      void	unlock();
      bool	trylock();

    private:
      HANDLE	_mutex;
    };

  }
}

#endif

