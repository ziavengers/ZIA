#ifndef READINI_HH_
#define READINI_HH_

#include <string>
#include "utils/parsing/ConsumerParser.hpp"
#include "Ini.hh"

namespace zia
{
  namespace utils
  {
    namespace ini
    {

      class ReadIni : public parsing::ConsumerParser
      {
      public:
	ReadIni(parsing::IProducterStream&);
	Ini parse();

      protected:
	bool readSpace();
	bool readSpaces();
	bool readComment();

	bool readSection(std::string&);
	bool readValue(std::string& value);
	
	bool readLine(Ini&);

	std::string _section;
      };

    }
  }
}

#endif
