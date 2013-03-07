#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <string>

#define CLASS_EXCEPTION(prefix) class Exception : public zia::utils::Exception \
  { \
public: \
    Exception(const std::string& reason = "", bool autolog = false) throw() : zia::utils::Exception(prefix + reason, autolog) {} \
  }

namespace zia
{
  namespace utils
  {

    class Exception : public std::exception
    {
    public:
      Exception(const std::string& reason = "", bool autolog = false) throw();
      virtual ~Exception() throw() { }
      void log() const throw();
      const char* what() const throw();

    private:
      std::string _reason;
    };

  }
}

#endif
