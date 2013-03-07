#ifndef ZIA_HH_
#define ZIA_HH_

#include <string>
#include "core/Settings.hh"
#include "core/Server.hh"
#include "core/ThreadPool.hh"

namespace zia
{
  namespace core
  {

    class Zia
    {
    public:
      // Zia(int, int, int);
      Zia(const std::string&);
      void run();
    private:
      Settings _settings;
      Server _server;
      ThreadPool _pool;
      
    };

  }
}

#endif
