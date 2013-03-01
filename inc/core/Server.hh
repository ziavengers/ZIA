#ifndef SERVER_HH_
#define SERVER_HH_

#include <list>

#include "core/Object.hpp"
#include "socket/Socket.hh"
#include "thread/Mutex.hh"

namespace zia
{
  namespace core
  {

    class Server : public Object
    {
    public:
      Server(int, int);
      void run();
      // void deleteClient(network::ISocket*);
    private:
      network::Socket _server;
      std::list< network::ISocket* > _clients;
      // std::list< network::ISocket* > _toDelete;
      // thread::Mutex _toDeleteMutex;
    };

  }
}

#endif
