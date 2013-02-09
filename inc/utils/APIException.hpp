#ifndef APIEXCEPTION_HPP_
#define APIEXCEPTION_HPP_

#include <exception>
#include <string>

#include "Logger.hh"

namespace zia
{
namespace utils
{

  class APIException : public std::exception
  {
  public:
    APIException(const std::string& s) : _msg(s) { }
    
    virtual ~APIException() throw() { }

    const char *	what() const throw() {
      LOG_ERROR(_msg);
      return _msg.c_str();
    }

  private:
    std::string _msg;
  };

}
}

#endif
