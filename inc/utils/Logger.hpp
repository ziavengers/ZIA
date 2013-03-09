#ifndef		UTILS_LOGGER_HPP_
# define	UTILS_LOGGER_HPP_

#include <string>
#include <fstream>
#include <map>
#include <iostream>

#include "LogLevel.hh"
#include "Singleton.hpp"
#include "NonCopyable.hh"
#include "thread/Mutex.hh"
#include "thread/Locker.hh"

namespace zia
{
  namespace utils
  {

    class Logger : public Singleton< Logger >, NonCopyable
    {
    public:
      void	logname(const std::string&);
      void	severity(log::level);
      void	display(bool);

      template < typename T >
      void log(T v, log::level level = log::INFO, bool endl = true)
      {
	thread::Locker lock(_mutex);
	if (_sev > level)
	  return ;
	if (_display)
	  {
	    std::cout << _color[level] << v << _color[log::DEFAULT];
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
      Logger& operator<<(log::level level)
      {
	thread::Locker lock(_mutex);
	_currentLevel = level;
	switch (level)
	  {
	  case log::DEBUG:
	    _file << "DEBUG:\t";
	    break;
	  case log::INFO:
	    _file << "INFO:\t";
	    break;
	  case log::WARNING:
	    _file << "WARNING:\t";
	    break;
	  case log::ERROR:
	    _file << "ERROR:\t";
	    break;
	  case log::CRITICAL:
	    _file << "CRITICAL:\t";
	    break;
	  default:
	    break;
	  }
	return *this;
      }
      Logger& operator<<(std::ostream& (*)(std::ostream&))
      {
	log("", _currentLevel);
	return *this;
      }


    public:
      Logger(const std::string& = "out.log", log::level = log::INFO);
      ~Logger();

    private:
      bool		_display;
      log::level	_sev;
      log::level	_currentLevel;
      std::string	_filename;
      std::ofstream	_file;  
      thread::Mutex	_mutex;
      std::map< log::level, std::string >		_color;
    };

  }  
}

#define LOG(sev)							\
  (*zia::utils::Logger::Singleton< zia::utils::Logger >::instance()) << sev

#define LOG_DEBUG LOG(zia::utils::log::DEBUG)
#define LOG_INFO LOG(zia::utils::log::INFO)
#define LOG_WARNING LOG(zia::utils::log::WARNING)
#define LOG_ERROR LOG(zia::utils::log::ERROR)
#define LOG_CRITICAL LOG(zia::utils::log::CRITICAL)

#endif		/* !LOGGER_HPP_*/
