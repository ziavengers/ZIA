#ifndef ISOCKET_HH_
#define ISOCKET_HH_

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

      virtual bool connect(const std::string& ip, int port) = 0;
      virtual bool bind(int port) = 0;
      virtual bool listen(int queueSize) = 0;
      virtual ISocket* accept() = 0;

      virtual size_t read(void*, size_t) = 0;
      virtual size_t write(const void*, size_t) = 0;

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

	virtual int run() = 0;

	virtual void set(ISocket* socket, SET set) = 0;
	virtual void clear(ISocket* socket, SET set) = 0;
	virtual bool isSet(ISocket* socket, SET set) = 0;
	virtual void zero(SET set) = 0;
      };

      class Exception : public utils::Exception
      {
      public:
      	Exception(const std::string& s) : utils::Exception(s)
      	{}
      };
    };

  }
}
#endif
