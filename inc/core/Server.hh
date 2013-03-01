#ifndef SERVER_HH_
#define SERVER_HH_

#include <list>
#include <queue>

#include "core/Object.hpp"
#include "socket/Socket.hh"
#include "thread/Mutex.hh"
#include "parsing_http/IProducterStream.hh"

namespace zia
{
  namespace core
  {

    class Server : public Object
    {
    public:
      class SocketStream : public IProducterStream, public Object
      {
      public:
	SocketStream(network::ISocket*);
	void read();
	std::string nextString();
	network::ISocket* socket();
      private:
	network::ISocket* _socket;
	thread::Mutex _mutex;
	std::queue< std::string > _strings;
	static const int _readSize = 256;
      };

      Server(int, int);
      void run();
    private:
      network::Socket _server;
      std::list< SocketStream* > _clients;
    };

  }
}

#endif
