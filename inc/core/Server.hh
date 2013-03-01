#ifndef SERVER_HH_
#define SERVER_HH_

#include <list>

#include "socket/Socket.hh"

namespace zia
{
  namespace core
  {

    class Server
    {
    public:
      Server(int, int);
      void run();
    private:
      network::Socket _server;
      std::list< network::ISocket* > _clients;
    };

  }
}

#endif
