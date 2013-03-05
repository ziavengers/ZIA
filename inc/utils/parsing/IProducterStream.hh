#ifndef IPRODUCTERSTREAM_HH_
#define IPRODUCTERSTREAM_HH_

#include <string>
#include "utils/Exception.hpp"

class IProducterStream
{
 public:
  virtual ~IProducterStream() {}
  virtual std::string nextString() = 0;

  CLASS_EXCEPTION("IProducerStream: ");
};

#endif
