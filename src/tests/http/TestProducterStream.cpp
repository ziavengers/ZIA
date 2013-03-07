#include "TestProducterStream.hh"
#include "utils/Exception.hpp"

TestProducterStream::TestProducterStream() : _strings(6), _it(_strings.begin())
{
  _strings[0] = "GET /";
  _strings[1] = " http/1.1\r\nHost: 127.0.0.1:8080\r\n";
  _strings[2] = "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n";
  _strings[3] = "Accept-Encoding: gzip, deflate\r\nConnection: keep-alive\r\n";
  _strings[4] = "\r\n";
  _strings[5] = "Ok";
}

std::string TestProducterStream::nextString()
{
  if (_it == _strings.end())
    throw zia::utils::Exception();
  std::string s = *_it;
  ++_it;
  return s;
}
