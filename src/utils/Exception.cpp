#include "utils/Exception.hpp"
#include "utils/Logger.hpp"

namespace zia
{
  namespace utils
  {

    Exception::Exception(const std::string& reason, bool autolog) throw() : _reason(reason)
    {
      if (autolog)
	log();
    }

    void Exception::log() const throw()
    {
      LOG_ERROR << _reason << std::endl;
    }

    const char* Exception::what() const throw()
    {
      return _reason.c_str();
    }

  }
}
