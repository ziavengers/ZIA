#include "core/Zia.hh"
#include "utils/Singleton.hpp"

namespace zia
{
  namespace core
  {

    Zia::Zia(const std::string& settingsFile) : _settings(settingsFile, true),
						_logger(_settings.getDefault("zia.log", "file", "logger")),
						_server(_settings.getTo< int >("port", "server"), _settings.getTo< int >("queue_size", "server")),
						_pool(_settings.getTo< int >("nb_threads", "threadPool"))
    {
      utils::Singleton< utils::Logger >::instance(&_logger);
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
