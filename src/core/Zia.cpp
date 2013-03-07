#include "core/Zia.hh"
#include "utils/Singleton.hpp"

namespace zia
{
  namespace core
  {

    Zia::Zia(const std::string& settingsFile) : _settings(settingsFile, true),
						_server(_settings.get< int >("port", "server"), _settings.get< int >("queue_size", "server")),
						_pool(_settings.get< int >("nb_threads", "threadPool"))
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
