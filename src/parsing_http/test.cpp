#include <iostream>
#include "parsing_http/TestProducterStream.hh"
#include "parsing_http/ParserHttp.hh"
#include "parsing_http/HttpMessage.hpp"

#include <fstream>





int main()
{


  TestProducterStream  ps;
  
  zia::http::message::HttpRequest r =  zia::http::message::HttpRequest::build(ps); 
  
  std::cout << r._method << std::endl;
  std::cout << r._url << std::endl;
  for (zia::http::message::HttpHeader::iterator it = r.header.begin(); it != r.header.end(); ++it)
    std::cout << it->first << ":" << it->second << std::endl;
  
  return 0;
}
