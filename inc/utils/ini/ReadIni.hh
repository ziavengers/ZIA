#ifndef READINI_HH_
#define READINI_HH_

#include <string>
#include "utils/parsing/ConsumerParser.hpp"
#include "Ini.hh"
#include "utils/Exception.hpp"

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
	bool readEndLine();

	bool readWord(std::string&);
	bool readString(std::string&);
	bool readValue(std::string&);

	bool readSection(std::string&);
	bool readAssignation(std::string&, std::string&);
	bool readInstruction(std::string&);
	
	bool readLine(Ini&);

	std::string _section;

      public:
	CLASS_EXCEPTION("zia::utils::ini::ReadIni");
      };

    }
  }
}

#endif
