#include "core/Server.hh"
#include "thread/Locker.hh"
#include "utils/Logger.hpp"

#include <cstdlib>
#include <signal.h>

void sigpass(int)
{
  throw zia::utils::Interrupt();
}

namespace zia
{
  namespace core
  {

    Server::SocketStream::SocketStream(network::ISocket* socket, int readSize) : _socket(socket), _readSize(readSize), _strings(), _uuid(), _buffWrite(), _readMutex(), _writeMutex()
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
    void Server::SocketStream::close()
    {
      delete _socket;
      _socket = 0;
    }
    network::ISocket* Server::SocketStream::socket()
    {
      return _socket;
    }
    const utils::uuid::uuid4& Server::SocketStream::uuid() const
    {
      return _uuid;
    }


    Server::Server(int port, int readSize, int queueSize, const std::string& sigNewClient, const std::string& sigReadClient) :
      Object(), _port(port), _readSize(readSize), _queueSize(queueSize), _server(), _clients(), _sigNewClient(sigNewClient), _sigReadClient(sigReadClient)
    {}
    Server::~Server()
    {
      while (_clients.size())
	{
	  delete _clients.front();
	  _clients.pop_front();
	}
    }

    void Server::run()
    {
      _server.bind(_port);
      _server.listen(_queueSize);

      network::Socket::Select select;
      std::list< SocketStream* >::iterator it;

      LOG_INFO << "Starting server on port " << _port << std::endl;
      try
	{
	  signal(SIGINT, sigpass);
	  while (true)
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
		  LOG_INFO << "Closing connection:\t" << *it << std::endl;
      	      	  _clients.remove(*it);
		  (*it)->deleteLater();
      	      	}

	      select.run();

      	      if (select.isSet(&_server, network::ISocket::Select::READ))
		{
		  SocketStream* client = new SocketStream(_server.accept(), _readSize);
		  _clients.push_back(client);
		  LOG_INFO << "Getting new connection:\t" << client << std::endl;
		  client->contextEmit(client->uuid().str(), _sigNewClient, _sigReadClient.data());
		}

      	      for (it = _clients.begin(); it != _clients.end(); ++it)
		{
		  if ((*it)->socket() && select.isSet((*it)->socket(), network::ISocket::Select::READ))
		    {
		      LOG_DEBUG << "Read on client\t" << *it << std::endl;
		      try
			{
			  (*it)->readBuff();
			  (*it)->contextEmit((*it)->uuid().str(), _sigReadClient);
			}
		      catch (network::ISocket::Exception& e)
			{
			  e.log();
			}
		    }
		  if ((*it)->socket() && select.isSet((*it)->socket(), network::ISocket::Select::WRITE))
		    {
		      try
			{
			  (*it)->writeBuff();
			}
		      catch (network::ISocket::Exception& e)
			{
			  LOG_CRITICAL << "aaa" << std::endl;
			  e.log();
			}
		    }
		}
	    }
	}
      catch (network::ISocket::Select::Exception& e)
      	{
      	  e.log();
      	}
      catch (utils::Interrupt& e)
	{
	  e.log();
	}
    }

  }
}
