#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <string>

#include "Logger.hh"

#define CLASS_EXCEPTION(prefix) class Exception : public zia::utils::Exception \
  { \
public: \
    Exception(const std::string& s) throw() : zia::utils::Exception(prefix + s) {} \
  }

namespace zia
{
namespace utils
{

  class Exception : public std::exception
  {
  public:
    Exception(const std::string& s = "") throw() : _msg(s) { }
    
    virtual ~Exception() throw() { }

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
