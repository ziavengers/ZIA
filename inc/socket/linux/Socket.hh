#ifndef SOCKET_HH_
#define SOCKET_HH_

#include <netinet/in.h>
#include <sys/select.h>

#include "../ISocket.hh"

namespace zia
{
  namespace network
  {

    class Socket : public ISocket
    {
    public:
      Socket();
      virtual ~Socket();

      bool connect(const std::string&, int);
      bool bind(int);
      bool listen(int);
      ISocket* accept();

      size_t read(void*, size_t);
      size_t write(const void*, size_t);

      class Select : public ISocket::Select
      {
      public:
	Select();
	virtual ~Select();

	int run();

	void set(ISocket*, SET);
	void clear(ISocket*, SET);
	bool isSet(ISocket*, SET);
	void zero(SET);

      protected:
	fd_set _sets[3];
	int _biggest;
      };

    protected:
      typedef int (*t_associate_func)(int, const struct sockaddr*, socklen_t);
      Socket(int, const struct sockaddr_in&);
      bool associate(const char*, int, t_associate_func);
      void reloadSin();

    protected:
      int _fd;
      struct sockaddr_in _sin;
    };

  }
}

#endif
