#include <exception>
#include "TestProducterStream.hh"

TestProducterStream::TestProducterStream() : _strings(5), _it(_strings.begin())
{
  _strings[0] = "GET toto.com http/1.1\n";
  _strings[1] = "tata:w\n";
  _strings[2] = "titi:e\n";
  _strings[3] = "\n";
  _strings[4] = "Ok";
}

std::string TestProducterStream::nextString()
{
  if (_it == _strings.end())
    throw std::exception();
  std::string s = *_it;
  ++_it;
  return s;
}
