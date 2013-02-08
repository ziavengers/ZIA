//
// AThread.hpp for hh in /home/nuts/local/ZIA/src/thread/linux
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Fri Jan 25 16:01:02 2013 Rivot Corentin
// Last update Fri Jan 25 16:11:56 2013 Rivot Corentin
//

#ifndef ATHREAD_HPP_
#define ATHREAD_HPP_

#include <pthread.h>

class AThread
{
public:
  void		start();
  void*		join();

  virtual void	init(void*) = 0;
  virtual void*	run() = 0;
  virtual void	pause() = 0;
  virtual void	resume() = 0;

protected:
  pthread_t	_thread;

private:
  static void*	startRoutine(void*);
};


#endif
