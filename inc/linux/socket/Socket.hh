#ifndef SOCKET_HH_
#define SOCKET_HH_

#include <netinet/in.h>
#include <sys/select.h>

#include "socket/ASocket.hh"

namespace zia
{
  namespace network
  {

    class Socket : public ASocket
    {
    public:
      Socket();
      virtual ~Socket();

      void connect(const std::string&, int);
      void bind(int);
      void listen(int);
      ISocket* accept();

      ssize_t read(void*, size_t);
      ssize_t write(const void*, size_t);

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
      int associate(const char*, int, t_associate_func);
      void reloadSin();
      void errnoThrow(const std::string&) throw(Exception);

    protected:
      int _fd;
      struct sockaddr_in _sin;
    };

  }
}

#endif
