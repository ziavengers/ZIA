#ifndef		LOGGER_HH_
# define	LOGGER_HH_

#include <string>
#include <fstream>
#include <map>

#include "Singleton.hpp"
#include "NonCopyable.hh"

namespace zia
{

  namespace utils
  {
    class Logger : public Singleton< Logger >, NonCopyable
    {
    public:

      enum LogLevel
	{
	  DEBUG = 0,
	  INFO,
	  NORMAL,
	  WARNING,
	  ERROR,
	  CRITIC
	};

      static Logger& logg;

      void	logname(const std::string&);
      void	severity(LogLevel);
      void	display(bool);

      void	log(LogLevel, const std::string&);
      void	log(const std::string&); // this method consider wich msg is NORMAL

      Logger&	operator<<(const std::string&);

    public:
      Logger();
      ~Logger();

    private:
      bool		_display;
      LogLevel		_sev;
      std::string	_filename;
      std::ofstream	_file;  
      std::map< LogLevel, std::string >		_color;
    };

  }

  template class utils::Singleton< utils::Logger >;

  extern utils::Logger& log;
  
}


#define LOG(sev, msg) \
  zia::utils::Logger::Singleton< zia::utils::Logger >::instance()->log(sev, msg); \

#define LOG_DEBUG(msg) LOG(zia::utils::Logger::DEBUG, msg)
#define LOG_INFO(msg) LOG(zia::utils::Logger::INFO, msg)
#define LOG_WARNING(msg) LOG(zia::utils::Logger::WARNING, msg)
#define LOG_ERROR(msg) LOG(zia::utils::Logger::ERROR, msg)
#define LOG_CRITIC(msg) LOG(zia::utils::Logger::CRITIC, msg)

#endif		/* !LOGGER_HH_*/
