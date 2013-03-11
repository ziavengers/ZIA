#ifndef CORE_SETTINGS_HPP_
#define CORE_SETTINGS_HPP_

#include <sstream>
#include "utils/ini/Ini.hh"
#include "utils/register.hpp"

namespace zia
{
  namespace core
  {

    class Settings
    {
    public:
      class ModuleInfo
      {
      public:
	ModuleInfo(const std::string&, const std::string&, const std::string&, const std::map< std::string, std::string >&);
	void load() const;
      private:
	const std::string& _url;
	const std::string& _sigInput;
	const std::string& _sigOutput;
	const std::map< std::string, std::string >& _args;
      };

      Settings(const std::string&, bool = false);
      void load();

      template < typename T >
      T getTo(const std::string& key, const std::string& section = "core") const
      {
	T val;
	const std::string& s(_ini[section][key]);
	std::istringstream iss(s);
	iss >> val;
	if (!iss.eof())
	  throw Exception("can't convert \"" + s + "\" to type " + getTypeName(T));
	return val;
      }
      template < typename T >
      T getDefaultTo(T defaultValue, const std::string& key, const std::string& section = "core") const
      {
	try
	  {
	    return getTo< T >(key, section);
	  }
	catch (utils::ini::Ini::Exception&)
	  {
	    return defaultValue;
	  }
      }
      const std::string& get(const std::string& key, const std::string& section = "core") const;
      const std::string& getDefault(const std::string&, const std::string& key, const std::string& section = "core") const;
      const utils::ini::Ini& ini() const;
      const std::list< ModuleInfo >& modulesInfos() const;

      CLASS_EXCEPTION("zia::core::Settings: ");
    private:
      const std::string& _filename;
      utils::ini::Ini _ini;
      std::list< ModuleInfo > _modulesInfos;
      static std::string _nullSig;
    };

  }
}

#endif
