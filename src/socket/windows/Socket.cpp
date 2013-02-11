#include <windows.h>

#include "socket/Socket.hh"

#include "utils/Logger.hh"

namespace zia
{

  namespace network
  {
    Socket::Socket()
    {
      WSADATA wsaData;

      if (WSAStartup(MAKEWORD(2,2), &wsaData) != NO_ERROR)
	{
	  LOG_ERROR("ERROR : WSAStartup failed!");
	  return;
	}
      _fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
      _sin.sin_family= AF_INET;
    }

    Socket::~Socket()
    {
      WSACleanup();
    }

    bool	Socket::connect(const std::string& ip, int port)
    {
      return associate(ip.data(), port, ::connect);
    }

    bool	Socket::bind(int port)
    {
      return associate(NULL, port, ::bind);
    }

    ISocket*	Socket::accept()
    {
      struct sockaddr_in csin;
      int sin_size = sizeof(csin);
      const int cfd = ::accept(_fd, reinterpret_cast< struct sockaddr* >(&csin), reinterpret_cast< int* >(&sin_size));
      return new Socket(cfd, csin);
    }

    size_t	Socket::read(void *buff, size_t len)
    {
      return ::recv(_fd, buff, len, 0);
    }

    size_t	Socket::write(const void* buff, size_t len)
    {
      return ::send(_fd, buff, len, 0);
    }

    Socket::Socket(int fd, const struct sockaddr_in& sin) : _fd(fd), _sin(sin)
    {
      reloadSin();
    }

    bool	Socket::associate(const char* ip, int port, Socket::t_associate_func f)
    {
      _sin.sin_port = htons(port);
      _sin.sin_addr.s_addr = (ip ? inet_addr(ip) : INADDR_ANY);
      f(_fd, reinterpret_cast< struct sockaddr* >(&_sin), sizeof(_sin));
      reloadSin();
      return true;
    }

    Socket::Select::Select() : _biggest(0)
    {
      zero(Socket::Select::READ);
      zero(Socket::Select::WRITE);
      zero(Socket::Select::ERROR);      
    }

    Socket::Select::~Select() {}

    int	Socket::Select::run()
    {
      return select(_biggest + 1,
		    &_sets[Socket::Select::READ],
		    &_sets[Socket::Select::WRITE],
		    &_sets[Socket::Select::ERROR], 0);
      // Ajouter gestion du timeout
    }

    void	Socket::Select::set(ISocket* s_, Socket::Select::SET set)
    {
      Socket* s = dynamic_cast< Socket* >(s_);
      if (s->_fd > _biggest)
	_biggest = s->_fd;
      FD_SET(s->_fd, &_sets[set]);
    }

    void	Socket::Select::clear(ISocket* s_, Socket::Select::SET set)
    {
      Socket* s = dynamic_cast< Socket* >(s_);
      FD_CLR(s->_fd, &_sets[set]);
    }

    bool	Socket::Select::isSet(ISocket* s_, Socket::Select::SET set)
    {
      Socket* s = dynamic_cast< Socket* >(s_);
      return FD_ISSET(s->_fd, &_sets[set]);
    }

    void	Socket::Select::zero(ISocket* s_, Socket::Select::SET set)
    {
      FD_ZERO(&_sets[set]);
    }
  }

}
