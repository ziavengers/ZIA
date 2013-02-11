#include <exception>
#include "parsing_http/TestProducterStream.hh"

TestProducterStream::TestProducterStream() : _strings(6), _it(_strings.begin())
{
  _strings[0] = "GET tot";
  _strings[1] = "o.com http/1.1\n";
  _strings[2] = "tata:wawa\n";
  _strings[3] = "titi:eugene\n";
  _strings[4] = "\n";
  _strings[5] = "Ok";
}

std::string TestProducterStream::nextString()
{
  if (_it == _strings.end())
    throw std::exception();
  std::string s = *_it;
  ++_it;
  return s;
}
