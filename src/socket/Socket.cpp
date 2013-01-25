#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "Socket.hh"

// Ajouter vérifs (fonctions systèmes + ptrs + dynamic_cast) & exceptions

Socket::Socket()
{
  struct protoent* pe;

  pe = getprotobyname("TCP");
  _fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  _sin.sin_family = AF_INET;
}

Socket::~Socket()
{
  close(_fd);
}

bool Socket::connect(const std::string& ip, int port)
{
  return associate(ip.data(), port, ::connect);
}

bool Socket::bind(int port)
{
  return associate(NULL, port, ::bind);
}

bool Socket::listen(int queueSize)
{
  ::listen(_fd, queueSize);
  return true;
}

ISocket* Socket::accept()
{
  struct sockaddr_in csin;
  int sin_size = sizeof(csin);
  const int cfd = ::accept(_fd, reinterpret_cast<struct sockaddr*>(&csin), reinterpret_cast<socklen_t*>(&sin_size));
  return new Socket(cfd, csin);
}


size_t Socket::read(void* buff, size_t len)
{
  return ::read(_fd, buff, len);
}

size_t Socket::write(const void* buff, size_t len)
{
  return ::write(_fd, buff, len);
}


Socket::Socket(int fd, const struct sockaddr_in& sin) : _fd(fd), _sin(sin)
{
  reloadSin();
}

bool Socket::associate(const char* ip, int port, Socket::t_associate_func f)
{
  _sin.sin_port = htons(port);
  _sin.sin_addr.s_addr = (ip ? inet_addr(ip) : INADDR_ANY);
  f(_fd, reinterpret_cast<struct sockaddr*>(&_sin), sizeof(_sin));
  reloadSin();
  return true;
}

void Socket::reloadSin()
{
  int sin_size = sizeof(_sin);
  getsockname(_fd, reinterpret_cast<struct sockaddr*>(&_sin), reinterpret_cast<socklen_t*>(&sin_size));
}


Socket::Select::Select() : _biggest(0)
{
  zero(Socket::Select::READ);
  zero(Socket::Select::WRITE);
  zero(Socket::Select::ERROR);
}

Socket::Select::~Select()
{}

int Socket::Select::run()
{
  return select(_biggest + 1,
		&_sets[Socket::Select::READ],
		&_sets[Socket::Select::WRITE],
		&_sets[Socket::Select::ERROR],
		0); // Ajouter gestion du timeout
}

void Socket::Select::set(ISocket* s_, Socket::Select::SET set)
{
  Socket* s = dynamic_cast<Socket*>(s_);
  if (s->_fd > _biggest)
    _biggest = s->_fd;
  FD_SET(s->_fd, &_sets[set]);
}

void Socket::Select::clear(ISocket* s_, Socket::Select::SET set)
{
  Socket* s = dynamic_cast<Socket*>(s_);
  FD_CLR(s->_fd, &_sets[set]);
}

bool Socket::Select::isSet(ISocket* s_, Socket::Select::SET set)
{
  Socket* s = dynamic_cast<Socket*>(s_);
  return FD_ISSET(s->_fd, &_sets[set]);
}

void Socket::Select::zero(Socket::Select::SET set)
{
  FD_ZERO(&_sets[set]);
}
