#include "core/Settings.hpp"
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

      // const utils::ini::Ini::Section& moduleSection = _ini["modules"];
      // std::list< utils::ini::Ini::Section::Instruction >::const_iterator it;
      // for (it = moduleSection.instructions().begin(); it != moduleSection.instructions().end(); ++it)
      // 	if (it->instr() == "add")
      // 	  {
      // 	    std::list< std::string >::const_iterator itarg;
      // 	    for (itarg = it->args().begin(); itarg != it->args().end(); ++itarg)
      // 	      std::cout << *itarg << " ";
      // 	    std::cout << std::endl;
      // 	  }
    }

    const std::string& Settings::get(const std::string& key, const std::string& section) const
    {
      return _ini[section][key];
    }
    const std::string& Settings::getDefault(const std::string& defaultValue, const std::string& key, const std::string& section) const
    {
      try
	{
	  return get(key, section);
	}
      catch (utils::ini::Ini::Exception&)
	{
	  return defaultValue;
	}
    }

    const utils::ini::Ini& Settings::ini() const
    {
      return _ini;
    }

  }
}
