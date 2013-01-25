//
// AThread.hh for hh in /home/nuts/local/ZIA/src/thread/linux
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Fri Jan 25 16:21:13 2013 Rivot Corentin
// Last update Fri Jan 25 16:22:36 2013 Rivot Corentin
//

#ifndef ATHREAD_HPP_
#define ATHREAD_HPP_

#pragma once

#include <windows.h>

class __declspec(dllexport) AThread
{
public:
  void		start();
  void*		join();

  virtual void	init(void*) = 0;
  virtual void*	run() = 0;
  virtual void	pause() = 0;
  virtual void	resume() = 0;

protected:
	HANDLE	_thread;

private:
  static void*	startRoutine(LPVOID);
};

#endif
