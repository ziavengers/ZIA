#ifndef SOCKET_SOCKET_HH_
#define SOCKET_SOCKET_HH_

#include <windows.h>
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

      bool	connect(const std::string& ip, int port);
      bool	bind(int port);
      bool	listen(int queueSize);
      ISocket*	accept();

      size_t	read(void*, size_t);
      size_t	write(const void*, size_t);

      
      class Select : public ISocket::Select
      {
	Select();
	virtual ~Select();

	int	run();
	
	void	set(ISocket*, SET);
	void	clear(ISocket*, SET);
	bool	isSet(ISocket*, SET);
	void	zero(SET);

      protected:
	fd_set	_sets[3];
	int	_biggest;
      };

    protected:
      typedef int (*t_associate_func)(int, const struct sockaddr*, int);

      Socket(int, const struct sockaddr_in&);
      bool	associate(const char*, int, t_associate_func);
      void	reloadSin();

      SOCKET	_fd;

      struct sockaddr_in	_sin;

    };
    
  }

}

#endif
