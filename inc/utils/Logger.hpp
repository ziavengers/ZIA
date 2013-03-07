#ifndef		LOGGER_HPP_
# define	LOGGER_HPP_

#include <string>
#include <fstream>
#include <map>
#include <iostream>

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
	  DEFAULT = 0,
	  DEBUG,
	  INFO,
	  WARNING,
	  ERROR,
	  CRITIC
	};

      void	logname(const std::string&);
      void	severity(LogLevel);
      void	display(bool);

      template < typename T >
      void log(T v, LogLevel level = INFO, bool endl = true)
      {
	if (_sev > level)
	  return ;
	if (_display && _file.is_open())
	  {
	    std::cout << _color[level] << v << _color[DEFAULT];
	    if (endl)
	      std::cout << std::endl;
	  }
	if (_file.is_open())
	  {
	    _file << v;
	    if (endl)
	      _file << std::endl;
	  }
      }

      template < typename T >
      Logger&	operator<<(T v)
      {
      	log(v, _currentLevel, false);
      	return *this;
      }
      Logger& operator<<(Logger::LogLevel l)
      {
	_currentLevel = l;
	return *this;
      }
      Logger& operator<<(std::ostream& (*f)(std::ostream&))
      {
	log("");
      }


    public:
      Logger(const std::string& = "out.log", LogLevel = INFO);
      ~Logger();

    private:
      bool		_display;
      LogLevel		_sev;
      LogLevel		_currentLevel;
      std::string	_filename;
      std::ofstream	_file;  
      std::map< LogLevel, std::string >		_color;
    };

  }  
}

#define LOG(sev)							\
  (*zia::utils::Logger::Singleton< zia::utils::Logger >::instance()) << sev

#define LOG_DEBUG LOG(zia::utils::Logger::DEBUG)
#define LOG_INFO LOG(zia::utils::Logger::INFO)
#define LOG_WARNING LOG(zia::utils::Logger::WARNING)
#define LOG_ERROR LOG(zia::utils::Logger::ERROR)
#define LOG_CRITIC LOG(zia::utils::Logger::CRITIC)

#endif		/* !LOGGER_HPP_*/
