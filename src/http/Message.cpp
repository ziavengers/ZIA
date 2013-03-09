#include "http/Message.hpp"

namespace zia
{
  namespace http
  {

    const std::string Message::_crlf("\r\n");
    const std::string Message::_httpVersion("HTTP/1.1");

    Message::Message(const std::string& version) : header(), _data(), _version(version)
    {}

    const std::string& Message::data() const
    {
      return _data;
    }

    std::string& Message::data()
    {
      return _data;
    }

  }
}
