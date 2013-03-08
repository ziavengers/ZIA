#include "core/Server.hh"
#include "thread/Locker.hh"
#include "utils/Logger.hpp"

#include <stdlib.h>

namespace zia
{
  namespace core
  {

    Server::SocketStream::SocketStream(network::ISocket* socket) : _socket(socket), _strings(), _buffWrite(), _readMutex(), _writeMutex()
    {}
    void Server::SocketStream::readBuff()
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
	      thread::Locker lock(_readMutex);
	      buff[len] = 0;
	      _strings.push(std::string(buff));
	    }
	}
    }
    void Server::SocketStream::writeBuff()
    {
      if (_socket && _buffWrite.size())
	{
	  thread::Locker lock(_writeMutex);
	  ssize_t len = _socket->write(_buffWrite.data(), _buffWrite.size());
	  _buffWrite = _buffWrite.substr(len);
	}
    }
    std::string Server::SocketStream::nextString()
    {
      if (!_socket)
      	throw Exception("end of stream");
      thread::Locker lock(_readMutex);
      std::string s = _strings.front();
      _strings.pop();
      return s;
    }
    void Server::SocketStream::write(const std::string& s)
    {
      thread::Locker lock(_writeMutex);
      _buffWrite += s;
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

      LOG_INFO << "Starting server on port " << _port << std::endl;
      try
	{
	  while (1)
	    {
	      select.zero(network::ISocket::Select::READ);
	      select.zero(network::ISocket::Select::WRITE);
	      select.set(&_server, network::ISocket::Select::READ);

      	      std::list< SocketStream* > toDelete;
	      for (it = _clients.begin(); it != _clients.end(); ++it)
		{
		  network::ISocket* s = (*it)->socket();
		  if (s)
		    {
		      select.set(s, network::ISocket::Select::READ);
		      select.set(s, network::ISocket::Select::WRITE);
		    }
		  else
		    toDelete.push_back(*it);
		}
      	      for (it = toDelete.begin(); it != toDelete.end(); ++it)
      	      	{
		  LOG_DEBUG << "Closing connection:\t" << *it << std::endl;
      	      	  _clients.remove(*it);
      	      	  delete *it;
      	      	}

	      select.run();

      	      if (select.isSet(&_server, network::ISocket::Select::READ))
		{
		  _clients.push_back(new SocketStream(_server.accept()));
		  LOG_DEBUG << "Getting new connection:\t" << _clients.back() << std::endl;
		}

      	      for (it = _clients.begin(); it != _clients.end(); ++it)
		{
		  if ((*it)->socket() && select.isSet((*it)->socket(), network::ISocket::Select::READ))
		    {
		      (*it)->readBuff();
		      (*it)->emit("SocketStream::readable");
		    }
		  if ((*it)->socket() && select.isSet((*it)->socket(), network::ISocket::Select::WRITE))
		    (*it)->writeBuff();
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
