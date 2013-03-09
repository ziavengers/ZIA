#include "http/Response.hh"

namespace zia
{
  namespace http
  {

    Response::Response(const std::string& statusCode, const std::string& status, const std::string& version) :
      Message(version), _statusCode(statusCode), _status(status)
    {}

    std::string Response::statusLine() const
    {
      return (_version + " " + _statusCode + " " + _status);
    }

  }
}
