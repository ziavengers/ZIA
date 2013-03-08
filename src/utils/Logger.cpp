#include <iostream>

#include "utils/Logger.hpp"

namespace zia
{

  namespace utils
  {

    Logger::Logger(const std::string& filename, log::level sev) :
      _display(true), _sev(sev), _currentLevel(log::INFO),
      _filename(filename), _file(_filename.c_str(), std::ios::out | std::ios::trunc)
    {
      _color[log::DEFAULT] = "\033[0m";
      _color[log::DEBUG] = "\033[36m";
      _color[log::INFO] = "\033[33m";
      _color[log::WARNING] = "\033[34m";
      _color[log::ERROR] = "\033[31m";
      _color[log::CRITICAL] = "\033[31;1m";
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

    void	Logger::severity(log::level l)
    {
      _sev = l;
    }

    void	Logger::display(bool b)
    {
      _display = b;
    }

  }
}
