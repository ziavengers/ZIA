#ifndef ISOCKET_HH_
#define ISOCKET_HH_

#include <string>

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
};

#endif
