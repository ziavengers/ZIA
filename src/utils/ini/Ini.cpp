#include "utils/ini/Ini.hh"

namespace zia
{
  namespace utils
  {
    namespace ini
    {

      Ini::Section::Instruction::Instruction(const std::string& instr) : _instr(instr), _args(), _kwargs()
      {}
      const std::list< std::string >& Ini::Section::Instruction::args() const
      {
	return _args;
      }
      const std::map< std::string, std::string >& Ini::Section::Instruction::kwargs() const
      {
	return _kwargs;
      }
      void Ini::Section::Instruction::addArg(const std::string& arg)
      {
	_args.push_back(arg);
      }
      const std::string& Ini::Section::Instruction::operator[](const std::string& key) const
      {
	try
	  {
	    return _kwargs.at(key);
	  }
	catch (...)
	  {
	    throw Exception("Can't find value " + key);
	  }
      }
      std::string& Ini::Section::Instruction::operator[](const std::string& key)
      {
	return _kwargs[key];
      }
      const std::string& Ini::Section::Instruction::instr() const
      {
	return _instr;
      }

      const std::list< Ini::Section::Instruction >& Ini::Section::instructions() const
      {
	return _instructions;
      }
      const std::map< std::string, std::string >& Ini::Section::vars() const
      {
	return _vars;
      }
      void Ini::Section::addInstruction(const Ini::Section::Instruction& instr)
      {
	_instructions.push_back(instr);
      }
      const std::string& Ini::Section::operator[](const std::string& key) const
      {
	try
	  {
	    return _vars.at(key);
	  }
	catch (...)
	  {
	    throw Exception("Can't find value " + key);
	  }
      }
      std::string& Ini::Section::operator[](const std::string& key)
      {
	return _vars[key];
      }
      void Ini::Section::extends(const Ini::Section& other)
      {
	std::list< Instruction >::const_iterator itinstr;
	for (itinstr = other.instructions().begin(); itinstr != other.instructions().end(); ++itinstr)
	  addInstruction(*itinstr);

	std::map< std::string, std::string >::const_iterator itvars;
	for (itvars = other.vars().begin(); itvars != other.vars().end(); ++itvars)
	  _vars[itvars->first] = itvars->second;
      }

      const std::map< std::string, Ini::Section >& Ini::sections() const
      {
	return _sections;
      }
      const Ini::Section& Ini::operator[](const std::string& key) const
      {
	try
	  {
	    return _sections.at(key);
	  }
	catch (...)
	  {
	    throw Exception("Can't find section " + key);
	  }
      }
      Ini::Section& Ini::operator[](const std::string& key)
      {
	return _sections[key];
      }
      void Ini::extends(const Ini& other)
      {
	std::map< std::string, Section >::iterator it;
	std::map< std::string, Section >::const_iterator ito;

	for (ito = other.sections().begin(); ito != other.sections().end(); ++ito)
	  {
	    it = _sections.find(ito->first);
	    if (it != _sections.end())
	      it->second.extends(ito->second);
	    else
	      _sections[it->first] = it->second;
	  }
      }

    }
  }
}
