#include <stdlib.h>
#include <list>
#include <iostream>
#include "socket/linux/Socket.hh"

int main(int ac, char** av)
{
  zia::network::ISocket* s = new zia::network::Socket();
  s->bind(atoi(av[1]));
  s->listen(5);

  std::list< zia::network::ISocket* > clients;
  std::list< zia::network::ISocket* >::iterator it;
  char buff[101];

  zia::network::ISocket::Select* select = new zia::network::Socket::Select;
  int error = 0;
  // Utiliser exception pour sortir ?
  while (!error)
    {
      select->zero(zia::network::ISocket::Select::READ);
      select->set(s, zia::network::ISocket::Select::READ);
      for (it = clients.begin(); it != clients.end(); ++it)
	select->set(*it, zia::network::ISocket::Select::READ);
      if (select->run() != -1)
	{
	  if (select->isSet(s, zia::network::ISocket::Select::READ))
	    {
	      zia::network::ISocket* c = s->accept();
	      clients.push_back(c);
	    }
	  std::list< zia::network::ISocket* > toDelete;
	  for (it = clients.begin(); it != clients.end(); ++it)
	    if (select->isSet(*it, zia::network::ISocket::Select::READ))
	      {
		zia::network::ISocket* c = *it;
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
