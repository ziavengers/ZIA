#ifndef HTTP_REQUESTPARSER_HH_
#define HTTP_REQUESTPARSER_HH_

#include "utils/parsing/ConsumerParser.hpp"
#include "http/Request.hh"

namespace zia
{
  namespace http
  {

    class RequestParser : public zia::utils::parsing::ConsumerParser
    {
    public:
      RequestParser(zia::utils::parsing::IProducterStream&);
      // bool readHttp(std::string&, std::string&, std::map< std::string, std::string >&, std::string&);
      Request readHttp();
      CLASS_EXCEPTION("zia::http::RequestParser: ");
    protected:
      bool readCRLF();
      bool readUntilCRLF(bool contains = true);
      bool readLWS();
    };

  }
}

#endif
