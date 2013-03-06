#include "utils/ini/Ini.hh"

namespace zia
{
  namespace utils
  {
    namespace ini
    {

      Ini::Section::Instruction::Instruction(const std::string& instr, const std::string& input, const std::string& output) : _instr(instr), _input(input), _output(output), _args(), _kwargs()
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
	return _kwargs.at(key);
      }
      std::string& Ini::Section::Instruction::operator[](const std::string& key)
      {
	return _kwargs[key];
      }
      const std::string& Ini::Section::Instruction::instr() const
      {
	return _instr;
      }
      const std::string& Ini::Section::Instruction::input() const
      {
	return _input;
      }
      const std::string& Ini::Section::Instruction::output() const
      {
	return _output;
      }
      void Ini::Section::Instruction::input(const std::string& input)
      {
	_input = input;
      }
      void Ini::Section::Instruction::output(const std::string& output)
      {
	_output = output;
      }

      const std::list< Ini::Section::Instruction >& Ini::Section::instructions() const
      {
	return _instructions;
      }
      const std::map< std::string, std::string >& Ini::Section::vars() const
      {
	return _vars;
      }
      void Ini::Section::addInstruction(const std::string& instr, const std::string& input, const std::string& output)
      {
	_instructions.push_back(Instruction(instr, input, output));
      }
      const std::string& Ini::Section::operator[](const std::string& key) const
      {
	return _vars.at(key);
      }
      std::string& Ini::Section::operator[](const std::string& key)
      {
	return _vars[key];
      }

      const std::map< std::string, Ini::Section >& Ini::sections() const
      {
	return _sections;
      }
      const Ini::Section& Ini::operator[](const std::string& key) const
      {
	return _sections.at(key);
      }
      Ini::Section& Ini::operator[](const std::string& key)
      {
	return _sections[key];
      }

    }
  }
}
