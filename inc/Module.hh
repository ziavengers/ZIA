#ifndef MODULE_HH_
#define MODULE_HH_

#include <list>
#include <string>

#include "IModule.hh"
#include "utils/Logger.hh"
#include "utils/Exception.hpp"


namespace zia
{
namespace module
{

  class	ModuleManagement
  {
  public:
    ModuleManagement();
    ~ModuleManagement();

    void	loadModule(IModule*) throw (utils::Exception);
    void	loadModule(const std::string& path) throw (utils::Exception);

    void	unloadModule(IModule*) throw (utils::Exception);
    void	unloadModule(const std::string& modName)  throw (utils::Exception);

  private:    
    std::list< IModule* >	_lModule;
  };

}
}

#endif
