#include "core/Zia.hh"
#include "utils/Singleton.hpp"

namespace zia
{
  namespace core
  {

    Zia::Zia(const std::string& settingsFile) :
      _settings(settingsFile, true),
      _logger(_settings.getDefault("out.log", "file", "logger")),
      _server(_settings.getTo< int >("port", "server"),
	      _settings.getDefaultTo< int >(1024, "read_size", "server"),
	      _settings.getDefaultTo< int >(5, "queue_size", "server"),
	      _settings.get("sig_new_client", "server"),
	      _settings.get("sig_read_client", "server")),
      _pool(_settings.getDefaultTo< int >(5, "nb_threads", "threadPool"))
    {
      std::map< std::string, utils::log::level > logLevels;
      logLevels["debug"] = utils::log::DEBUG;
      logLevels["info"] = utils::log::INFO;
      logLevels["warning"] = utils::log::WARNING;
      logLevels["error"] = utils::log::ERROR;
      logLevels["critical"] = utils::log::CRITICAL;
      _logger.severity(logLevels[_settings.getDefault("info", "severity", "logger")]);
      utils::Singleton< utils::Logger >::instance(&_logger);
      utils::Singleton< ThreadPool >::instance(&_pool);
    }

    void Zia::run()
    {
      try
	{
	  _pool.start();
	  std::list< Settings::ModuleInfo >::const_iterator it;
	  for (it = _settings.modulesInfos().begin(); it != _settings.modulesInfos().end(); ++it)
	    it->load();
	  _server.run();
	}
      catch (utils::Exception& e)
	{
	  e.log();
	}
    }

  }
}
