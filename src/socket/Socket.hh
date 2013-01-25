#ifndef SOCKET_HH_
#define SOCKET_HH_

#include <netinet/in.h>

#include "ISocket.hh"

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

protected:
  typedef int (*t_associate_func)(int, const struct sockaddr*, socklen_t);
  Socket(int, const struct sockaddr_in&);
  bool associate(const char*, int, t_associate_func);
  void reloadSin();

protected:
  int _fd;
  struct sockaddr_in _sin;
};

#endif
