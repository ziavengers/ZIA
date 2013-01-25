#include <stdlib.h>
#include <list>
#include <iostream>
#include "Socket.hh"

int main(int ac, char** av)
{
  ISocket* s = new Socket();
  s->bind(atoi(av[1]));
  s->listen(5);

  std::list<ISocket*> clients;
  std::list<ISocket*>::iterator it;
  char buff[101];

  ISocket::Select* select = new Socket::Select;
  int error = 0;
  // Utiliser exception pour sortir ?
  while (!error)
    {
      select->zero(ISocket::Select::READ);
      select->set(s, ISocket::Select::READ);
      for (it = clients.begin(); it != clients.end(); ++it)
	select->set(*it, ISocket::Select::READ);
      if (select->run() != -1)
	{
	  if (select->isSet(s, ISocket::Select::READ))
	    {
	      ISocket* c = s->accept();
	      clients.push_back(c);
	    }
	  std::list<ISocket*> toDelete;
	  for (it = clients.begin(); it != clients.end(); ++it)
	    if (select->isSet(*it, ISocket::Select::READ))
	      {
		ISocket* c = *it;
		int len = c->read(buff, 100);
		if (len > 0)
		  {
		    buff[len] = 0;
		    std::cout << buff;
		  }
		else
		  {
		    toDelete.push_back(c);
		  }
	      }
	  for (it = toDelete.begin(); it != toDelete.end(); ++it)
	    {
	      clients.remove(*it);
	      delete *it;
	    }
	}
      else
	error = 1;
    }
  delete s;
}
