//
// Mutex.hh<2> for hh in /home/nuts/local/ZIA/src/thread/linux
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Fri Jan 25 16:22:15 2013 Rivot Corentin
// Last update Fri Feb  8 14:24:28 2013 Rivot Corentin
//

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

