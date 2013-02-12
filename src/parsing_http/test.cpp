#include <iostream>
#include "parsing_http/TestProducterStream.hh"
#include "parsing_http/ParserHttp.hh"

#include <fstream>

int main()
{
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
