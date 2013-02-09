#include <iostream>

#include "utils/Logger.hh"

namespace zia
{

  utils::Logger& log = *(utils::Logger::Singleton< zia::utils::Logger >::instance());

namespace utils
{

  Logger&	Logger::logg = *(utils::Singleton< utils::Logger >::instance());


  Logger::Logger() : _display(true), _sev(NORMAL), _filename("out.log"),
		     _file(_filename.c_str(), std::ios::out | std::ios::trunc)
  {
    _color[DEBUG] = "\033[36m";
    _color[INFO] = "\033[33m";
    _color[NORMAL] = "\033[0m";
    _color[WARNING] = "\033[34m";
    _color[ERROR] = "\033[31m";
    _color[CRITIC] = "\033[31;1m";
    _file << "New log:" << std::endl;
  }

  Logger::~Logger()
  {
    if (_file.is_open())
      _file.close();
  }

  void	Logger::logname(const std::string& s)
  {
    if (_file.is_open())
      _file.close();
    _file.open(s.c_str(), std::ios::out | std::ios::trunc);
    _filename = s;
  }

  void	Logger::severity(Logger::LogLevel l)
  {
    _sev = l;
  }

  void	Logger::display(bool b)
  {
    _display = b;
  }

  void	Logger::log(LogLevel l, const std::string& s)
  {
    if (_sev <= l)
      {
	std::cout << _color[l];
	log(s);
      }
  }

  void	Logger::log(const std::string& s)
  {
    if (_display && _file.is_open())
      {	
	std::cout << s << _color[NORMAL] << std::endl;
      }
    if (_file.is_open())
      _file << s << std::endl;
  }

  Logger&	Logger::operator<<(const std::string& s)
  {
    log(s);
    return *this;
  }
}
}

