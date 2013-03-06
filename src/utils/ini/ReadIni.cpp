#include "utils/ini/ReadIni.hh"
#include <iostream>

namespace zia
{
  namespace utils
  {
    namespace ini
    {

      ReadIni::ReadIni(parsing::IProducterStream& prod) : parsing::ConsumerParser(prod)
      {}

      Ini ReadIni::parse()
      {
	Ini ini;
	std::string sectionName;
	while (!readEOF())
	  if (!readLine(ini))
	    {
	      std::cout << "parsing Error" << std::endl;
	      break ;
	    }
	return ini;
      }

      bool ReadIni::readSpace()
      {
	return (read(' ') || read('\t'));
      }
      bool ReadIni::readSpaces()
      {
	if (!readSpace())
	  return false;
	while (readSpace())
	  ;
	return true;
      }
      bool ReadIni::readComment()
      {
	saveContext();
	readSpaces();
	if (!read('#') && !read(';'))
	  {
	    restoreContext();
	    return false;
	  }
	validContext();
	if (!readUntil< char >('\n'))
	  readUntilEOF();
	return true;
      }

      bool ReadIni::readSection(std::string& name)
      {
	saveContext();
	readSpaces();
	if (read('[') && beginCapture("sectionName") && readIdentifier() && endCapture("sectionName", name) && read(']'))
	  {
	    validContext();
	    return true;
	  }
	restoreContext();
	return false;
      }

      bool ReadIni::readLine(Ini& ini)
      {
	std::string sectionName;
	std::string key;
	std::string value;
	std::vector< std::string > ends(4);
	ends[0] = " ";
	ends[1] = "#";
	ends[2] = ";";
	ends[3] = "\n";
	if (readComment() || read('\n'))
	  return true;
	readSpaces();
	if (saveContext() && readSection(sectionName))
	  {
	    readSpaces();
	    if (read('\n') || readEOF() || readComment())
	      {
		validContext();
		_section = sectionName;
		return true;
	      }
	    restoreContext();
	  }
	else if (saveContext() && beginCapture("key") && readIdentifier() && endCapture("key", key) && ignore(readSpaces()) && read('=') && ignore(readSpaces()) && beginCapture("value") && (readUntil(ends, false) || readUntilEOF()) && endCapture("value", value))
	  {
	    readSpaces();
	    if (read('\n') || readEOF() || readComment())
	      {
		ini[_section][key] = value;
		validContext();
		return true;
	      }
	    restoreContext();
	  }
	return false;
      }

    }
  }
}
