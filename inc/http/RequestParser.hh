#ifndef HTTP_REQUESTPARSER_HH_
#define HTTP_REQUESTPARSER_HH_

#include "utils/parsing/ConsumerParser.hpp"

// namespace zia
// {
//   namespace http
//   {

    class ParserHttp : public zia::utils::parsing::ConsumerParser
    {
    public:
      ParserHttp(zia::utils::parsing::IProducterStream&);
      bool readHttp(std::string&, std::string&, std::map< std::string, std::string >&, std::string&);
    protected:
      bool readCRLF();
      bool readUntilCRLF();
      bool readLWS();
    };

//   }
// }

#endif
