#include "utils/Exception.hpp"
#include "utils/Logger.hpp"

namespace zia
{
  namespace utils
  {

    Exception::Exception(const std::string& reason, log::level level) throw() :
      _reason(reason), _level(level), _logged(false)
    {}

    void Exception::log() throw()
    {
      if (!_logged)
	{
	  LOG(_level) << _reason << std::endl;
	  _logged = true;
	}
    }

    const char* Exception::what() const throw()
    {
      return _reason.c_str();
    }

  }
}
