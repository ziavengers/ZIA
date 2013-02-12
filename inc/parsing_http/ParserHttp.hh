#ifndef PARSERHTTP_HH_
#define PARSERHTTP_HH_

#include "ConsumerParser.hpp"

class ParserHttp : public ConsumerParser
{
public:
  ParserHttp(IProducterStream&);
  bool readHttp(std::string&, std::string&, std::map< std::string, std::string >&, std::string&);
  bool readCRLF();
  bool readLWS();
};

#endif
