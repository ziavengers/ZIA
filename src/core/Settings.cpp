#include "core/Settings.hh"
#include "utils/parsing/FileStream.hh"
#include "utils/ini/ReadIni.hh"

#include <iostream>

namespace zia
{
  namespace core
  {

    Settings::Settings(const std::string& filename, bool autoload) : _filename(filename)
    {
      if (autoload)
	load();
    }

    void Settings::load()
    {
      utils::parsing::FileStream fs(_filename);
      _ini = utils::ini::ReadIni(fs, "core").parse();

      const utils::ini::Ini::Section& moduleSection = _ini["modules"];
      std::list< utils::ini::Ini::Section::Instruction >::const_iterator it;
      for (it = moduleSection.instructions().begin(); it != moduleSection.instructions().end(); ++it)
	if (it->instr() == "add")
	  {
	    std::list< std::string >::const_iterator itarg;
	    for (itarg = it->args().begin(); itarg != it->args().end(); ++itarg)
	      std::cout << *itarg << " ";
	    std::cout << std::endl;
	  }
    }

#include <stdlib.h>
    template < >
    int Settings::get< int >(const std::string& key, const std::string& section) const
    {
      return atoi(_ini[section][key].data());
    }

    const utils::ini::Ini& Settings::ini() const
    {
      return _ini;
    }

  }
}
