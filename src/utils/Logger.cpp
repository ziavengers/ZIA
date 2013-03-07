#include <iostream>

#include "utils/Logger.hpp"

namespace zia
{

  namespace utils
  {

    Logger::Logger(const std::string& filename, LogLevel sev) : _display(true), _sev(sev), _currentLevel(INFO),
								_filename(filename), _file(_filename.c_str(), std::ios::out | std::ios::trunc)
    {
      _color[DEFAULT] = "\033[0m";
      _color[DEBUG] = "\033[36m";
      _color[INFO] = "\033[33m";
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

  }
}
