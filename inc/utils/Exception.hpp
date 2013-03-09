#ifndef UTILS_EXCEPTION_HPP_
#define UTILS_EXCEPTION_HPP_

#include <exception>
#include <string>

#include "LogLevel.hh"

#define CLASS_EXCEPTION(prefix) class Exception : public zia::utils::Exception \
  { \
public: \
    Exception(const std::string& reason = "", zia::utils::log::level level = zia::utils::log::ERROR) throw() : zia::utils::Exception(prefix + reason, level) {} \
  }

namespace zia
{
  namespace utils
  {

    class Exception : public std::exception
    {
    public:
      Exception(const std::string& reason = "", log::level level = log::ERROR) throw();
      virtual ~Exception() throw() { }
      void log() throw();
      const char* what() const throw();

    private:
      std::string _reason;
      log::level _level;
      bool _logged;
    };

    class Interrupt : public Exception
    {
    public:
      Interrupt() : Exception("Interrupt", log::INFO)
      {}
    };

  }
}

#endif
