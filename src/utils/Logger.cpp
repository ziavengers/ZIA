/*
** Logger.cpp for  in /home/nuts/local/ZIA/src/utils
** 
** Made by 
** Login   <nuts@epitech.net>
** 
** Started on  Tue Feb 05 18:53:49 2013 
// Last update Wed Feb  6 21:41:29 2013 Rivot Corentin
*/

#include <iostream>

#include "Logger.hh"

namespace zia
{

  utils::Logger& log = *(utils::Logger::Singleton< zia::utils::Logger >::instance());

namespace utils
{

  Logger&	Logger::logg = *(utils::Singleton< utils::Logger >::instance());


  Logger::Logger() : _display(true), _sev(NORMAL), _filename("out.log"),
		     _file(_filename.c_str(), std::ios::out | std::ios::trunc)
  {
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
    if (_sev >= l)
      log(s);
  }

  void	Logger::log(const std::string& s)
  {
    if (_display && _file.is_open())
      std::cout << s << std::endl;
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

