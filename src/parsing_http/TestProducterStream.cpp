#include "parsing_http/TestProducterStream.hh"
#include "utils/Exception.hpp"

TestProducterStream::TestProducterStream() : _strings(6), _it(_strings.begin())
{
  _strings[0] = "GET tot";
  _strings[1] = "o.com http/1.1\r\n";
  _strings[2] = "tata:wawa\r\n";
  _strings[3] = "titi:eugene\r\n";
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
