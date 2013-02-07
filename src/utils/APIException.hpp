//
// APIException.hpp for hh in /home/nuts/local/ZIA/src
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Thu Feb  7 14:47:34 2013 Rivot Corentin
// Last update Thu Feb  7 14:52:51 2013 Rivot Corentin
//

#ifndef APIEXCEPTION_HPP_
#define APIEXCEPTION_HPP_

#include <exception>
#include <string>

namespace zia
{
namespace utils
{

  class APIException : public std::exception
  {
  public:
    APIException(const std::string& s) : _msg(s) { }
    
    virtual ~APIException() throw() ;

    const char *	what() const throw() {
      return _msg.c_str();
    }

  private:
    std::string _msg;
  };

}
}

#endif
