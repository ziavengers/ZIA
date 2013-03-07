#include "core/Zia.hh"
#include "utils/Singleton.hpp"

namespace zia
{
  namespace core
  {

    Zia::Zia(const std::string& settingsFile) :
      _settings(settingsFile, true),
      _logger(_settings.getDefault("zia.log", "file", "logger")),
      _server(_settings.getTo< int >("port", "server"),
	      _settings.getDefaultTo< int >(5, "queue_size", "server")),
      _pool(_settings.getDefaultTo< int >(5, "nb_threads", "threadPool"))
    {
      utils::Singleton< utils::Logger >::instance(&_logger);
      utils::Singleton< ThreadPool >::instance(&_pool);
      std::map< std::string, utils::Logger::LogLevel > logLevels;
      logLevels["debug"] = utils::Logger::DEBUG;
      logLevels["info"] = utils::Logger::INFO;
      logLevels["warning"] = utils::Logger::WARNING;
      logLevels["error"] = utils::Logger::ERROR;
      logLevels["critic"] = utils::Logger::CRITIC;
      _logger.severity(logLevels[_settings.getDefault("info", "severity", "logger")]);
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
