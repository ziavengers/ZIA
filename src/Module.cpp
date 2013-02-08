//
// Module.cpp for hh in /home/nuts/local/ZIA/src
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Thu Feb  7 14:37:14 2013 Rivot Corentin
// Last update Fri Feb  8 11:58:49 2013 Rivot Corentin
//

#include <Module.hh>

namespace zia
{
namespace module
{

  ModuleManagement::ModuleManagement()
  {
  }

  ModuleManagement::~ModuleManagement()
  {
  }

  void	ModuleManagement::loadModule(IModule* m) throw (utils::APIException)
  {
    if (!m)
      throw utils::APIException("ModuleManagement::loadModule : null pointer");
    zia::log << "Add module named " << m->name();
    _lModule.push_back(m);
  }

  void	ModuleManagement::loadModule(const std::string& path) throw (utils::APIException)
  {
    throw utils::APIException("ModuleManagement::loadModule : not implemented yet");
  }

  void	ModuleManagement::unloadModule(IModule* m) throw (utils::APIException)
  {
    if (!m)
      throw utils::APIException("ModuleManagement::loadModule : null pointer");
    unloadModule(m->name());
  }

  void	ModuleManagement::unloadModule(const std::string& modName) throw (utils::APIException)
  {
    std::list< IModule* >::iterator	it;

    for (it = _lModule.begin(); it != _lModule.end(); ++it)
      {
	if ((*it)->name() == modName)
	  {
	    zia::log << "Unload module named " << modName;
	    _lModule.erase(it);
	  }
      }
  }
}
}
