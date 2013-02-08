//
// Module.hh for hh in /home/nuts/local/ZIA/src
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Thu Feb  7 13:45:14 2013 Rivot Corentin
// Last update Thu Feb  7 16:43:42 2013 Rivot Corentin
//

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
