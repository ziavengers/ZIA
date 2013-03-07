#include <iostream>
#include "TestProducterStream.hh"
#include "http/ParserHttp.hh"
#include "http/HttpMessage.hpp"

#include <fstream>



void	tests()
{
  TestProducterStream  ps;
  
  zia::http::message::HttpRequest r =  zia::http::message::HttpRequest::build(ps); 
  
  std::cout << r._method << std::endl;
  std::cout << r._url << std::endl;
  for (zia::http::message::HttpHeader::iterator it = r.header.begin(); it != r.header.end(); ++it)
    std::cout << it->first << ":" << it->second << std::endl;
  std::cout << "content : " << r.content() << std::endl;
 
}

int main()
{
  tests();

  
  return 0;
}
