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


      ReadIni::ReadIni(parsing::IProducterStream& prod, const std::string& section) : parsing::ConsumerParser(prod), _section(section)
      {}

      Ini ReadIni::parse()
      {
	Ini ini;
	std::string sectionName;
	while (!readEOF())
	  if (!readLine(ini))
	    throw Exception("Error during parsing");
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
      bool ReadIni::readEndLine()
      {
	readSpaces();
	return (read('\n') || readEOF() || readComment());
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
      bool ReadIni::readAssignation(std::string& key, std::string& value)
      {
	saveContext();
	if (beginCapture("key") && readIdentifier() && endCapture("key", key) && ignore(readSpaces()) && read('=') && ignore(readSpaces()) && readValue(value))
	  {
	    validContext();
	    return true;
	  }
	restoreContext();
	return false;
      }
      bool ReadIni::readInstruction(std::string& cmd)
      {
	saveContext();
	if (beginCapture("cmd") && readIdentifier() && endCapture("cmd", cmd) && ignore(readSpaces()) && read(':'))
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
	std::string cmd;

	readSpaces();
	if (readEndLine())
	  return true;
	if (readSection(sectionName) && readEndLine())
	  {
	    _section = sectionName;
	    return true;
	  }
	else if (readAssignation(key, value) && readEndLine())
	  {
	    ini[_section][key] = value;
	    return true;
	  }
	else if (readInstruction(cmd))
	  {
	    Ini::Section::Instruction instr(cmd);
	    saveContext();
	    bool breaked = false;
	    while (!breaked && !readEndLine())
	      {
		readSpaces();		
		if (readAssignation(key, value))
		  instr[key] = value;
		else if (readValue(cmd))
		  instr.addArg(cmd);
		else
		  breaked = true;
	      }
	    if (!breaked)
	      {
		validContext();
		ini[_section].addInstruction(instr);
		return true;
	      }
	    restoreContext();
	  }
	return false;
      }

    }
  }
}
