#ifndef UTILS_PARSING_FILESTREAM_HH_
#define UTILS_PARSING_FILESTREAM_HH_

#include <fstream>
#include "IProducterStream.hh"

namespace zia
{
  namespace utils
  {
    namespace parsing
    {

      class FileStream : public IProducterStream
      {
      public:
	FileStream(const std::string&);
	~FileStream();
	std::string nextString();
	void close();
      private:
	std::ifstream _f;
	static const size_t readSize = 512;
	char _buff[readSize + 1];
      };

    }
  }
}

#endif
