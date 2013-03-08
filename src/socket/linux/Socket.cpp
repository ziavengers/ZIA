#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
extern const char *sys_errlist[];

#include "socket/Socket.hh"

namespace zia
{
  namespace network
  {

    Socket::Socket()
    {
      struct protoent* pe;

      pe = getprotobyname("TCP");
      _fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
      int on = 1;
      setsockopt(_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
      _sin.sin_family = AF_INET;
    }

    Socket::~Socket()
    {
      close(_fd);
    }

    void Socket::connect(const std::string& ip, int port)
    {
      if (associate(ip.data(), port, ::connect))
	errnoThrow("connect");
    }

    void Socket::bind(int port)
    {
      if (associate(NULL, port, ::bind))
	errnoThrow("bind");
    }

    void Socket::listen(int queueSize)
    {
      if (::listen(_fd, queueSize))
	errnoThrow("listen");
    }

    ISocket* Socket::accept()
    {
      struct sockaddr_in csin;
      int sin_size = sizeof(csin);
      const int cfd = ::accept(_fd, reinterpret_cast<struct sockaddr*>(&csin), reinterpret_cast<socklen_t*>(&sin_size));
      if (cfd < 0)
	errnoThrow("accept");
      return new Socket(cfd, csin);
    }


    ssize_t Socket::read(void* buff, size_t len)
    {
      ssize_t r = ::read(_fd, buff, len);
      if (r < 0)
	errnoThrow("read");
      return r;
    }

    ssize_t Socket::write(const void* buff, size_t len)
    {
      ssize_t r = ::write(_fd, buff, len);
      if (r < 0)
	errnoThrow("write");
      return r;
    }


    Socket::Socket(int fd, const struct sockaddr_in& sin) : _fd(fd), _sin(sin)
    {
      reloadSin();
    }

    int Socket::associate(const char* ip, int port, Socket::t_associate_func f)
    {
      _sin.sin_port = htons(port);
      _sin.sin_addr.s_addr = (ip ? inet_addr(ip) : INADDR_ANY);
      int r = f(_fd, reinterpret_cast<struct sockaddr*>(&_sin), sizeof(_sin));
      if (!r)
	reloadSin();
      return r;
    }

    void Socket::reloadSin()
    {
      int sin_size = sizeof(_sin);
      getsockname(_fd, reinterpret_cast<struct sockaddr*>(&_sin), reinterpret_cast<socklen_t*>(&sin_size));
    }

    void Socket::errnoThrow(const std::string& func) throw(Exception)
    {
      std::string reason(sys_errlist[errno]);
      throw Exception(func + ": " + reason);
    }


    Socket::Select::Select() : _biggest(0)
    {
      zero(Socket::Select::READ);
      zero(Socket::Select::WRITE);
      zero(Socket::Select::ERROR);
    }

    Socket::Select::~Select()
    {}

    void Socket::Select::run()
    {
      if (select(_biggest + 1,
		    &_sets[Socket::Select::READ],
		    &_sets[Socket::Select::WRITE],
		    &_sets[Socket::Select::ERROR],
		 0) < 0) // Ajouter gestion du timeout
      {
	std::string reason(sys_errlist[errno]);
	  throw Exception("run: " + reason);
      }
    }

    void Socket::Select::set(ISocket* s_, Socket::Select::SET set)
    {
      Socket* s = dynamic_cast< Socket* >(s_);
      if (s->_fd > _biggest)
	_biggest = s->_fd;
      FD_SET(s->_fd, &_sets[set]);
    }

    void Socket::Select::clear(ISocket* s_, Socket::Select::SET set)
    {
      Socket* s = dynamic_cast< Socket* >(s_);
      FD_CLR(s->_fd, &_sets[set]);
    }

    bool Socket::Select::isSet(ISocket* s_, Socket::Select::SET set)
    {
      Socket* s = dynamic_cast< Socket* >(s_);
      return FD_ISSET(s->_fd, &_sets[set]);
    }

    void Socket::Select::zero(Socket::Select::SET set)
    {
      FD_ZERO(&_sets[set]);
    }

  }
}
