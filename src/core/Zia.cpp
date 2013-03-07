#include "core/Zia.hh"
#include "utils/Singleton.hpp"

namespace zia
{
  namespace core
  {

    // Zia::Zia(int port, int serverQueueSize, int nbThreads) : _server(port, serverQueueSize), _pool(nbThreads)
    // {
    //   utils::Singleton< ThreadPool >::instance(&_pool);
    // }
    Zia::Zia(const std::string& settingsFile) : _settings(settingsFile, true),
						_server(_settings.get< int >("port"), _settings.get< int >("queueSize")),
						_pool(_settings.get< int >("nbThreads"))
    {
      utils::Singleton< ThreadPool >::instance(&_pool);
    }

    void Zia::run()
    {
      try
	{
	  _pool.start();
	  _server.run();
	}
      catch (utils::Exception& e)
	{
	  e.log();
	}
    }

  }
}
