#ifndef INI_HH_
#define INI_HH_

#include <map>
#include <list>
#include <string>

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
	    Instruction(const std::string&, const std::string& = "", const std::string& = "");
	    const std::list< std::string >& args() const;
	    const std::map< std::string, std::string >& kwargs() const;
	    void addArg(const std::string&);
	    const std::string& operator[](const std::string&) const;
	    std::string& operator[](const std::string&);

	    const std::string& instr() const;
	    const std::string& input() const;
	    const std::string& output() const;
	    void input(const std::string&);
	    void output(const std::string&);
	  protected:
	    std::string _instr;
	    std::string _input;
	    std::string _output;
	    std::list< std::string > _args;
	    std::map< std::string, std::string > _kwargs;
	  };

	  const std::list< Instruction >& instructions() const;
	  const std::map< std::string, std::string >& vars() const;
	  void addInstruction(const std::string&, const std::string& = "", const std::string& = "");
	  const std::string& operator[](const std::string&) const;
	  std::string& operator[](const std::string&);
	protected:
	  std::map< std::string, std::string > _vars;
	  std::list< Instruction > _instructions;
	};

	const std::map< std::string, Section >& sections() const;
	const Section& operator[](const std::string&) const;
	Section& operator[](const std::string&);

      protected:
	std::map< std::string, Section > _sections;
      };

    }
  }
}

#endif
