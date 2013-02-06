#include <exception>
#include <iostream>
#include "TestProducterStream.hh"
// #include "ConsumerParser.hpp"
#include "ParserHttp.hh"

#include <fstream>

int main()
{
  TestProducterStream ps;
  // ConsumerParser cp(ps);

  // std::string out;
  // cp.beginCapture("a");
  // cp.readUntilEOF();
  // cp.endCapture("a", out);
  // std::cout << out << std::endl;
  ParserHttp p(ps);
  std::map<std::string, std::string> header;
  std::map<std::string, std::string>::iterator it;
  p.readHttp(header);
  for (it = header.begin(); it != header.end(); ++it)
    std::cout << it->first << " : " << it->second << std::endl;
}
