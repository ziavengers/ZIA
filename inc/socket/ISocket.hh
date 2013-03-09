#ifndef SOCKET_ISOCKET_HH_
#define SOCKET_ISOCKET_HH_

#include <string>
#include "utils/Exception.hpp"

namespace zia
{
  namespace network
  {

    class ISocket
    {
    public:
      virtual ~ISocket() {}

      virtual void connect(const std::string& ip, int port) = 0;
      virtual void bind(int port) = 0;
      virtual void listen(int queueSize) = 0;
      virtual ISocket* accept() = 0;

      virtual ssize_t read(void*, size_t) = 0;
      virtual ssize_t write(const void*, size_t) = 0;

      class Select
      {
      public:
	enum SET
	  {
	    READ = 0,
	    WRITE = 1,
	    ERROR = 2
	  };
	virtual ~Select() {}

	virtual void run() = 0;

	virtual void set(ISocket* socket, SET set) = 0;
	virtual void clear(ISocket* socket, SET set) = 0;
	virtual bool isSet(ISocket* socket, SET set) = 0;
	virtual void zero(SET set) = 0;

	CLASS_EXCEPTION("zia::network::ISocket::Select: ");
      };

      CLASS_EXCEPTION("zia::network::ISocket: ");
    };

  }
}
#endif
