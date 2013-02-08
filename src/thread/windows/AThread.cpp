//
// AThread.cpp<2> for hh in /home/nuts/local/ZIA/src/thread/linux
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Fri Jan 25 16:21:38 2013 Rivot Corentin
// Last update Fri Feb  8 11:00:04 2013 Antoine Rozo
//

#include "inc/windows/AThread.h"

void	AThread::start()
{
	// Normalement il ne faut pas caster en LPTHREAD... peut crash sous windows 64bits, à voir
	if ((_thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&AThread::startRoutine, this, 0, NULL)) == NULL)
	  ;//throw CoreException("AThread::start fail!");
}

void*	AThread::join()
{
	LPDWORD	ret;

	if (ResumeThread(_thread) == -1)
	  ;//throw CoreException("AThread::join fail!");
	if (GetExitCodeThread(_thread, ret) == 0)
	  ;//throw CoreException("AThread::join fail!");
	return ret;
}

void*	AThread::startRoutine(LPVOID lpParam)
{
	AThread*	t;

	t = reinterpret_cast< AThread* >(lpParam);
	return t->run();
}
