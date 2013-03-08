#ifndef UUID_HH_
#define UUID_HH_

#include <string>

namespace zia
{
  namespace utils
  {
    namespace uuid
    {

      class UUID
      {
      public:
	virtual ~UUID() {}
	virtual const std::string& str() const = 0;
      };

      class UUID4 : public UUID
      {
      public:
	UUID4();
	const std::string& str() const;
      private:
	static const int _nbBytes = 16;
	static const char* _hexa;
	unsigned char _bytes[_nbBytes];
	std::string _s;
      };

      typedef UUID4 uuid4;

    }
  }
}

#endif
