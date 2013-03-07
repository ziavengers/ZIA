#ifndef SETTINGS_HH_
#define SETTINGS_HH_

#include "utils/ini/Ini.hh"

namespace zia
{
  namespace core
  {

    class Settings
    {
    public:
      Settings(const std::string&, bool = false);
      void load();
      template < typename T >
      T get(const std::string&, const std::string& = "core") const;
      const utils::ini::Ini& ini() const;
    private:
      const std::string& _filename;
      utils::ini::Ini _ini;
    };

  }
}

#endif
