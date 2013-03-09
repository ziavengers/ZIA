#ifndef HTTP_REQUEST_HH_
#define HTTP_REQUEST_HH_

#include "Message.hpp"

namespace zia
{
  namespace http
  {

    class Request : public Message
    {
    public:
      Request(const std::string& method, const std::string& url = "/", const std::string& version = _httpVersion);
      std::string statusLine() const;
    private:
      std::string _method;
      std::string _url;
    };

  }
}

#endif
