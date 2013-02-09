#ifndef MODULE_HH_
#define MODULE_HH_

#include <list>
#include <string>

#include "IModule.hh"
#include "utils/Logger.hh"
#include "utils/APIException.hpp"


namespace zia
{
namespace module
{

  class	ModuleManagement
  {
  public:
    ModuleManagement();
    ~ModuleManagement();

    void	loadModule(IModule*) throw (utils::APIException);
    void	loadModule(const std::string& path) throw (utils::APIException);

    void	unloadModule(IModule*) throw (utils::APIException);
    void	unloadModule(const std::string& modName)  throw (utils::APIException);

  private:    
    std::list< IModule* >	_lModule;
  };

}
}

#endif
