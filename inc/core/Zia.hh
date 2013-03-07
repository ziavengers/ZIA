#ifndef ZIA_HH_
#define ZIA_HH_

#include <string>
#include "core/Settings.hpp"
#include "utils/Logger.hpp"
#include "core/Server.hh"
#include "core/ThreadPool.hh"

namespace zia
{
  namespace core
  {

    class Zia
    {
    public:
      Zia(const std::string&);
      void run();
    private:
      Settings _settings;
      utils::Logger _logger;
      Server _server;
      ThreadPool _pool;
      
    };

  }
}

#endif
