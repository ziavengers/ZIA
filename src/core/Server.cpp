#include "core/Server.hh"
#include "thread/Locker.hh"

namespace zia
{
  namespace core
  {

    Server::SocketStream::SocketStream(network::ISocket* socket) : _socket(socket), _mutex(), _strings()
    {}
    void Server::SocketStream::read()
    {
      if (_socket)
	{
	  ssize_t len;
	  char buff[_readSize + 1];
	  if (!(len = _socket->read(buff, _readSize)))
	    {
	      delete _socket;
	      _socket = 0;
	    }
	  else
	    {
	      thread::Locker lock(_mutex);
	      buff[len] = 0;
	      _strings.push(std::string(buff));
	    }
	}
    }
    std::string Server::SocketStream::nextString()
    {
      if (!_socket)
	throw Exception("end of stream");
      thread::Locker lock(_mutex);
      std::string s = _strings.front();
      _strings.pop();
      return s;
    }
    network::ISocket* Server::SocketStream::socket()
    {
      return _socket;
    }


    Server::Server(int port, int queueSize) : Object(), _port(port), _queueSize(queueSize), _server(), _clients()
    {}

    void Server::run()
    {
      _server.bind(_port);
      _server.listen(_queueSize);

      network::Socket::Select select;
      std::list< SocketStream* >::iterator it;

      try
	{
	  while (1)
	    {
	      select.zero(network::ISocket::Select::READ);
	      select.set(&_server, network::ISocket::Select::READ);

      	      std::list< SocketStream* > toDelete;
	      for (it = _clients.begin(); it != _clients.end(); ++it)
		{
		  network::ISocket* s = (*it)->socket();
		  if (s)
		    select.set(s, network::ISocket::Select::READ);
		  else
		    toDelete.push_back(*it);
		}
	      select.run();

      	      if (select.isSet(&_server, network::ISocket::Select::READ))
      		_clients.push_back(new SocketStream(_server.accept()));

      	      for (it = _clients.begin(); it != _clients.end(); ++it)
      		if ((*it)->socket() && select.isSet((*it)->socket(), network::ISocket::Select::READ))
      		  {
		    (*it)->read();
		    (*it)->emit("SocketStream::readable");
      		  }

      	      for (it = toDelete.begin(); it != toDelete.end(); ++it)
      	      	{
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

  }
}
