#include "http/Request.hh"

namespace zia
{
  namespace http
  {

    Request::Request(const std::string& method, const std::string& url, const std::string& version) :
      Message(version), _method(method), _url(url)
    {}

    std::string Request::statusLine() const
    {
      return (_method + " " + _url + " " + _version);
    }

  }
}
