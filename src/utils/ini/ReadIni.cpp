#include "utils/ini/ReadIni.hh"
#include <iostream>

namespace zia
{
  namespace utils
  {
    namespace ini
    {

      char escapedLetter(char c)
      {
	switch (c)
	  {
	  case 'a':
	    return '\a';
	  case 'b':
	    return '\b';
	  case 't':
	    return '\t';
	  case 'n':
	    return '\n';
	  case 'v':
	    return '\v';
	  case 'f':
	    return '\f';
	  case 'r':
	    return '\r';
	  default:
	    return c;
	  }
      }

      void appendReplacingEscapedLetter(std::string& dest, const std::string& src)
      {
	if (dest.size())
	  {
	    dest.append(1, escapedLetter(src[0]));
	    dest.append(src, 1, src.size() - 1);
	  }
	else
	  dest.append(src);
      }


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

      bool ReadIni::readWord(std::string& word)
      {
	std::vector< char > ends(3);
	ends[0] = ' ';
	ends[1] = '\t';
	ends[2] = '\n';
	return (beginCapture("word") && (readUntil(ends, false) || readUntilEOF()) && endCapture("word", word));
      }
      bool ReadIni::readString(std::string& string)
      {
	std::string tmp;
	string = "";
	saveContext();
	if (read('"'))
	  {
	    beginCapture("string");
	    while (!peek('"'))
	      {
		if (peek('\\'))
		  {
		    endCapture("string", tmp);
		    appendReplacingEscapedLetter(string, tmp);
		    read('\\');
		    beginCapture("string");
		  }
		if (!readRange(' ', '~'))
		  break ;
	      }
	    endCapture("string", tmp);
	    appendReplacingEscapedLetter(string, tmp);
	    if (read('"'))
	      {
		validContext();
		return true;
	      }
	  }
	restoreContext();
	return false;
      }

      bool ReadIni::readSection(std::string& name)
      {
	saveContext();
	if (read('[') && beginCapture("sectionName") && readIdentifier() && endCapture("sectionName", name) && read(']'))
	  {
	    validContext();
	    return true;
	  }
	restoreContext();
	return false;
      }

      bool ReadIni::readValue(std::string& value)
      {
	std::string tmp;
	value = "";
	if (readString(value))
	  return true;
	else if (readWord(value))
	  return true;
	return false;
      }

      bool ReadIni::readLine(Ini& ini)
      {
	std::string sectionName;
	std::string key;
	std::string value;
	std::string cmd;
	std::vector< std::string > ends(4);
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
	  }
	restoreContext();
	if (saveContext() && beginCapture("key") && readIdentifier() && endCapture("key", key) && ignore(readSpaces()) && read('=') && ignore(readSpaces()) && readValue(value))
	  {
	    readSpaces();
	    if (read('\n') || readEOF() || readComment())
	      {
		ini[_section][key] = value;
		validContext();
		return true;
	      }
	  }
	restoreContext();
	if (saveContext() && beginCapture("cmd") && readIdentifier() && endCapture("cmd", cmd) && ignore(readSpaces()) && read(':'))
	  {
	    Ini::Section::Instruction instr(cmd);
	    ini[_section].addInstruction(instr);
	  }
	restoreContext();
	return false;
      }

    }
  }
}
