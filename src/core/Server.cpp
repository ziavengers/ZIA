#include "core/Server.hh"
#include "thread/Locker.hh"
#include <algorithm>
#include <iostream>

namespace zia
{
  namespace core
  {

    Server::Server(int port, int queueSize) : Object(), _server(), _clients()// , _toDelete(), _toDeleteMutex()
    {
      _server.bind(port);
      _server.listen(queueSize);
    }

    void Server::run()
    {
      network::Socket::Select select;
      char buff[101];
      std::list< network::ISocket* >::iterator it;

      // connect("socket_close", utils::bind(&Server::deleteClient, *this, static_cast< network::Socket::ISocket* >(0)));

      try
	{
	  while (1)
	    {
	      // {
	      // 	thread::Locker lock(_toDeleteMutex);
	      // 	for (it = _toDelete.begin(); it != _toDelete.end(); ++it)
	      // 	  {
	      // 	    _clients.remove(*it);
	      // 	    // delete *it;
	      // 	  }
	      // 	_toDelete.clear();
	      // }

	      select.zero(network::ISocket::Select::READ);
	      select.set(&_server, network::ISocket::Select::READ);
	      for (it = _clients.begin(); it != _clients.end(); ++it)
		select.set(*it, network::ISocket::Select::READ);
	      select.run();

      	      if (select.isSet(&_server, network::ISocket::Select::READ))
      		_clients.push_back(_server.accept());

      	      std::list< zia::network::ISocket* > toDelete;
      	      for (it = _clients.begin(); it != _clients.end(); ++it)
      		if (select.isSet(*it, network::ISocket::Select::READ))
      		  {
		    // std::cout << "!!!" << std::endl;
      		    network::ISocket* c = *it;
      		    int len = c->read(buff, 100);
      		    if (len > 0)
      		      {
      		    	buff[len] = 0;
      		    	std::cout << buff;
      		      }
      		    else
      		      toDelete.push_back(c);
		    // emit("socket_readable", *it);
      		  }

      	      for (it = toDelete.begin(); it != toDelete.end(); ++it)
      	      	{
		  // std::cout << "???" << std::endl;
      	      	  _clients.remove(*it);
      	      	  delete *it;
      	      	}
	    }
	}
      catch (network::ISocket::Select::Exception& e)
	{
	  e.log();
	}
    }

    // void Server::deleteClient(network::ISocket* c)
    // {
    //   thread::Locker lock(_toDeleteMutex);
    //   std::list< network::ISocket* >::iterator it = std::find(_toDelete.begin(), _toDelete.end(), c);
    //   if (it == _toDelete.end())
    // 	return ;
    //   _toDelete.push_back(c);
    //   std::cout << "???" << std::endl;
    // }

  }
}
