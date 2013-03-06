#include "utils/parsing/FileStream.hh"

namespace zia
{
  namespace utils
  {
    namespace parsing
    {

      FileStream::FileStream(const std::string& filename) : _f(filename.data(), std::ios::in)
      {
	if (_f.fail())
	  throw Exception("bad file");
      }

      std::string FileStream::nextString()
      {
	if (_f.eof())
	  throw Exception("end of stream");
	if (_f.fail() || _f.bad())
	  throw Exception("error");
	_f.clear();
	_f.read(_buff, readSize);
	_buff[_f.gcount()] = 0;
	return std::string(_buff);
      }

    }
  }
}
