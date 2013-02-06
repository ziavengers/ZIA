#ifndef IPRODUCTERSTREAM_HH_
#define IPRODUCTERSTREAM_HH_

#include <string>

class IProducterStream
{
 public:
  virtual ~IProducterStream() {}
  virtual std::string nextString() = 0;
};

#endif
