#ifndef TESTPRODUCTERSTREAM_HH_
#define TESTPRODUCTERSTREAM_HH_

#include <vector>
#include "utils/parsing/IProducterStream.hh"

class TestProducterStream : public IProducterStream
{
public:
  TestProducterStream();
  std::string nextString();
private:
  std::vector<std::string> _strings;
  std::vector<std::string>::iterator _it;
};

#endif
