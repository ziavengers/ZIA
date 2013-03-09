#ifndef HTTP_RESPONSE_HH_
#define HTTP_RESPONSE_HH_

#include "Message.hpp"

namespace zia
{
  namespace http
  {

    class Response : public Message
    {
    public:
      Response(const std::string& statusCode, const std::string& status, const std::string& version = _httpVersion);
      std::string statusLine() const;
    private:
      std::string _statusCode;
      std::string _status;
    };

  }
}

#endif
