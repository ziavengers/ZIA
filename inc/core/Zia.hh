#ifndef ZIA_HH_
#define ZIA_HH_

#include "core/Server.hh"
#include "core/ThreadPool.hh"

namespace zia
{
  namespace core
  {

    class Zia
    {
    public:
      Zia(int, int, int);
      void run();
    private:
      Server _server;
      ThreadPool _pool;
      
    };

  }
}

#endif
