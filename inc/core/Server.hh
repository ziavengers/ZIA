#ifndef CORE_SERVER_HH_
#define CORE_SERVER_HH_

#include <list>
#include <queue>

#include "core/Object.hpp"
#include "socket/Socket.hh"
#include "thread/Mutex.hh"
#include "utils/parsing/IProducterStream.hh"
#include "utils/uuid.hh"

namespace zia
{
  namespace core
  {

    class Server : public Object
    {
    public:
      class SocketStream : public utils::parsing::IProducterStream, public Object
      {
      public:
	SocketStream(network::ISocket*, int);
	TYPENAME(zia::core::Server::SocketStream);
	void readBuff();
	void writeBuff();
	std::string nextString();
	void write(const std::string&);
	SocketStream& operator<<(const std::string&);
	bool closed() const;
	void close();
	network::ISocket* socket();
	const utils::uuid::uuid4& uuid() const;
      private:
	network::ISocket* _socket;
	int _readSize;
	std::queue< std::string > _strings;
	utils::uuid::uuid4 _uuid;
	std::string _buffWrite;
	thread::Mutex _readMutex;
	thread::Mutex _writeMutex;
      };

      Server(int, int, int, const std::string&, const std::string&);
      ~Server();
      TYPENAME(zia::core::Server);
      void run();
    private:
      int _port;
      int _readSize;
      int _queueSize;
      network::Socket _server;
      std::list< SocketStream* > _clients;
      std::string _sigNewClient;
      std::string _sigReadClient;
    };

  }
}

#endif
