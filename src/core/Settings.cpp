#include "core/Settings.hpp"
#include "utils/parsing/FileStream.hh"
#include "utils/ini/ReadIni.hh"
#include "utils/Logger.hpp"
#include "core/module/ModuleManagement.hh"

#include <iostream>

namespace zia
{
  namespace core
  {

    Settings::ModuleInfo::ModuleInfo(const std::string& url, const std::string& sigInput, const std::string& sigOutput, const std::map< std::string, std::string >& args) :
      _url(url), _sigInput(sigInput), _sigOutput(sigOutput), _args(args)
    {}
    void Settings::ModuleInfo::load() const
    {
      utils::Singleton< module::ModuleManagement >::instance()->loadModule(_url, _sigInput.substr(1), _sigOutput.substr(1), _args);
    }

    Settings::Settings(const std::string& filename, bool autoload) : _filename(filename), _modulesInfos()
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
      std::list< std::string >::const_iterator itargs;
      for (it = moduleSection.instructions().begin(); it != moduleSection.instructions().end(); ++it)
      	if (it->instr() == "add")
      	  {
	    const std::string* url = 0;
	    const std::string* sigInput = 0;
	    const std::string* sigOutput = 0;
	    for (itargs = it->args().begin(); itargs != it->args().end(); ++itargs)
	      {
		if (!url)
		  url = &*itargs;
		else if (!sigInput && (*itargs)[0] == '<')
		  sigInput = &*itargs;
		else if (!sigOutput && (*itargs)[0] == '>')
		  sigOutput = &*itargs;
	      }
	    if (url && sigInput && sigOutput)
	      _modulesInfos.push_back(ModuleInfo(*url, *sigInput, *sigOutput, it->kwargs()));
	    else
	      throw Exception("load: Incomplete add instruction");
	  }
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

    const std::list< Settings::ModuleInfo >& Settings::modulesInfos() const
    {
      return _modulesInfos;
    }

  }
}
