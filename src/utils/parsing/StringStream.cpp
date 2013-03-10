#include "utils/parsing/StringStream.hh"

namespace zia
{
  namespace utils
  {
    namespace parsing
    {

      StringStream::StringStream(const std::string& data, size_t portionSize) : _data(data), _portionSize(portionSize)
      {}
      std::string StringStream::nextString()
      {
	std::string s;
	if (!_portionSize)
	  {
	    s = _data;
	    _data = "";
	  }
	else
	  {
	    s = _data.substr(0, _portionSize);
	    _data = _data.substr(_portionSize);
	  }
	return s;
      }
      void StringStream::close()
      {}

    }
  }
}
