#include "utils/uuid.hh"
#include "utils/random.hh"

namespace zia
{
  namespace utils
  {
    namespace uuid
    {

      const char* UUID4::_hexa = "0123456789abcdef";

      UUID4::UUID4() : _bytes(), _s()
      {
	for (int i = 0; i < _nbBytes; ++i)
	  _bytes[i] = rand(255);
	_bytes[6] = (_bytes[6] & 0x0f) | 0x40;
	_bytes[8] = (_bytes[8] & 0x3f) | 0x80;

	for (int i = 0; i < _nbBytes; ++i)
	  {
	    if (i == 6 || i == 8 || i == 10)
	      _s += "-";
	    _s += _hexa[_bytes[i] / 16];
	    _s += _hexa[_bytes[i] % 16];
	  }
      }

      const std::string& UUID4::str() const
      {
	return _s;
      }

    }
  }
}
