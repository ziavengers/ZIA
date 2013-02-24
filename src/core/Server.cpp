#include "core/Server.hh"
#include <iostream>

namespace zia
{
  namespace core
  {

    Server::Server(int port, int queueSize) : _server(), _clients()
    {
      _server.bind(port);
      _server.listen(queueSize);
    }

    void Server::run()
    {
      network::Socket::Select select;
      char buff[101];
      bool error = false; // Remplacer par exceptions
      while (!error)
	{
	  select.zero(network::ISocket::Select::READ);
	  select.set(&_server, network::ISocket::Select::READ);
	  for (it = _clients.begin(); it != _clients.end(); ++it)
	    select.set(*it, network::ISocket::Select::READ);
	  if (select->run() != -1)
	    {
	      if (select.isSet(&_server, network::ISocket::Select::READ))
		_clients.push_back(_server.accept());
	      std::list< zia::network::ISocket* > toDelete;
	      for (it = _clients.begin(); it != _clients.end(); ++it)
		if (select.isSet(*it, network::ISocket::Select::READ))
		  {
		    network::ISocket* c = *it;
		    int len = c->read(buff, 100);
		    if (len > 0)
		      {
			buff[len] = 0;
			std::cout << buff;
		      }
		    else
		      toDelete.push_back(c);
		  }
	      for (it = toDelete.begin(); it != todelete.end(); ++it)
		{
		  _clients.remove(*it);
		  delete *it;
		}
	    }
	  else
	    error = true;
	}
    }

  }
}
