#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <string>

#include "Logger.hh"

#define CLASS_EXCEPTION(prefix) class Exception : public zia::utils::Exception \
  { \
public: \
    Exception(const std::string& s, bool autolog = false) throw() : zia::utils::Exception(prefix + s, autolog) {} \
  }

namespace zia
{
namespace utils
{

  class Exception : public std::exception
  {
  public:
    Exception(const std::string& s = "", bool autolog = false) throw() : _msg(s) {
      if (autolog)
	log();
    }
    
    virtual ~Exception() throw() { }

    void log() const throw() {
      LOG_ERROR(_msg);
    }
    const char *	what() const throw() {
      return _msg.c_str();
    }

  private:
    std::string _msg;
  };

}
}

#endif
