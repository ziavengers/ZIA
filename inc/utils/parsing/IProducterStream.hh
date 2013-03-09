#ifndef UTILS_PARSING_IPRODUCTERSTREAM_HH_
#define UTILS_PARSING_IPRODUCTERSTREAM_HH_

#include <string>
#include "utils/Exception.hpp"

namespace zia
{
  namespace utils
  {
    namespace parsing
    {

      class IProducterStream
      {
      public:
	virtual ~IProducterStream() {}
	virtual std::string nextString() = 0;
	virtual void close() = 0;
	
	CLASS_EXCEPTION("zia::utils::parsing::IProducerStream: ");
      };

    }
  }
}

#endif
