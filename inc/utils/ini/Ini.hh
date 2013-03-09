#ifndef UTILS_INI_INI_HH_
#define UTILS_INI_INI_HH_

#include <map>
#include <list>
#include <string>
#include "utils/Exception.hpp"

namespace zia
{
  namespace utils
  {
    namespace ini
    {

      class Ini
      {
      public:
	class Section
	{
	public:
	  class Instruction
	  {
	  public:
	    Instruction(const std::string&);
	    const std::list< std::string >& args() const;
	    const std::map< std::string, std::string >& kwargs() const;
	    void addArg(const std::string&);
	    const std::string& operator[](const std::string&) const;
	    std::string& operator[](const std::string&);

	    const std::string& instr() const;

	  protected:
	    std::string _instr;
	    std::list< std::string > _args;
	    std::map< std::string, std::string > _kwargs;
	  };

	  const std::list< Instruction >& instructions() const;
	  const std::map< std::string, std::string >& vars() const;
	  void addInstruction(const Instruction&);
	  const std::string& operator[](const std::string&) const;
	  std::string& operator[](const std::string&);

	  void extends(const Section&);

	protected:
	  std::map< std::string, std::string > _vars;
	  std::list< Instruction > _instructions;
	};

	const std::map< std::string, Section >& sections() const;
	const Section& operator[](const std::string&) const;
	Section& operator[](const std::string&);

	void extends(const Ini&);

	CLASS_EXCEPTION("zia::utils::ini::Ini: ");

      protected:
	std::map< std::string, Section > _sections;
      };

    }
  }
}

#endif
