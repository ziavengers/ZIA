#ifndef SERVER_HH_
#define SERVER_HH_

#include <list>
#include <queue>

#include "core/Object.hpp"
#include "socket/Socket.hh"
#include "thread/Mutex.hh"
#include "utils/parsing/IProducterStream.hh"

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
	SocketStream(network::ISocket*);
	void readBuff();
	void writeBuff();
	std::string nextString();
	void write(const std::string&);
	network::ISocket* socket();
      private:
	network::ISocket* _socket;
	std::queue< std::string > _strings;
	std::string _buffWrite;
	thread::Mutex _readMutex;
	thread::Mutex _writeMutex;
	static const int _readSize = 256;
      };

      Server(int, int);
      void run();
    private:
      int _port;
      int _queueSize;
      network::Socket _server;
      std::list< SocketStream* > _clients;
    };

  }
}

#endif
