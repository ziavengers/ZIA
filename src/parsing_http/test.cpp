#include <iostream>
#include "parsing_http/TestProducterStream.hh"
#include "parsing_http/ParserHttp.hh"
#include "parsing_http/HttpMessage.hpp"

#include <fstream>

int main()
{
  /*
    httpMessages
  */
  http::message::HttpRequest msg;
  // http::message::equivalent to : 
  // http::message::HttpMessage msg;
  // or http::message::HttpReply msg;
  msg.header["content-type"] = "text/html";
  msg.header["key"] = "value";
  std::cout << msg.header["content-type"] << std::endl;


  return 0;


  TestProducterStream ps;
  ParserHttp p(ps);
  std::string method;
  std::string url;
  std::map< std::string, std::string > header;
  std::map< std::string, std::string >::iterator it;
  std::string content;
  if (p.readHttp(method, url, header, content))
    {
      std::cout << "{" << method << "}" << std::endl;
      std::cout << "{" << url << "}" << std::endl;
      for (it = header.begin(); it != header.end(); ++it)
	std::cout << "-> " << it->first << " : " << it->second;
      std::cout << "{" << content << "}" << std::endl;
    }
}
