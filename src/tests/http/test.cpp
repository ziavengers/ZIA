#include <iostream>
#include "TestProducterStream.hh"
#include "http/Request.hh"
#include "http/Response.hh"
#include "http/RequestParser.hh"

#include <fstream>

// void	tests()
// {
//   TestProducterStream  ps;
  
//   zia::http::HttpRequest r =  zia::http::HttpRequest::build(ps); 
  
//   std::cout << r._method << std::endl;
//   std::cout << r._url << std::endl;
//   for (zia::http::HttpHeader::iterator it = r.header.begin(); it != r.header.end(); ++it)
//     std::cout << it->first << ":" << it->second << std::endl;
//   std::cout << "content : " << r.content() << std::endl;
 
// }

int main()
{
  zia::http::Request request("GET");
  request.header["Content-Type"] = "text/html";
  request.data() += "tutu";
  request.write(std::cout);

  std::cout << std::endl << "==============" << std::endl;

  zia::http::Response response("200", "OK");
  response.header["Content-Type"] = "text/html";
  response.data() += "tutu";
  response.write(std::cout);

  std::cout << std::endl;

  return 0;
}
