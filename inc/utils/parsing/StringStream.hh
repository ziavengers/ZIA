#ifndef UTILS_PARSING_STRINGSTREAM_HH_
#define UTILS_PARSING_STRINGSTREAM_HH_

#include "IProducterStream.hh"

namespace zia
{
  namespace utils
  {
    namespace parsing
    {

      class StringStream : public IProducterStream
      {
      public:
	StringStream(const std::string&, size_t = 0);
	std::string nextString();
	void close();
      private:
	std::string _data;
	size_t _portionSize;
      };

    }
  }
}

#endif
