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

  void	ModuleManagement::loadModule(IModule* m) throw (utils::Exception)
  {
    if (!m)
      throw utils::Exception("ModuleManagement::loadModule : null pointer");
    zia::log << "Add module named " << m->name();
    _lModule.push_back(m);
  }

  void	ModuleManagement::loadModule(const std::string& path) throw (utils::Exception)
  {
    try
      {
	_lib.add(path);
	IModule*	(*fptr)(void);
	fptr = _lib.getFunction< IModule* (*)(void) >(path, "createModule");

	_lModule.push_back(fptr());
      }
    catch (utils::Exception& e)
      {
    	throw (e);
      }
    catch (...)
      {
    	throw utils::Exception("ModuleManagement::loadModule(std::string) : Unknow error catched");
      }
  }

  void	ModuleManagement::unloadModule(IModule* m) throw (utils::Exception)
  {
    if (!m)
      throw utils::Exception("ModuleManagement::loadModule : null pointer");
    unloadModule(m->name());
  }

  void	ModuleManagement::unloadModule(const std::string& modName) throw (utils::Exception)
  {
    std::list< IModule* >::iterator	it;

    for (it = _lModule.begin(); it != _lModule.end(); ++it)
      {
	if ((*it)->name() == modName)
	  {
	    zia::log << "Unload module named " << modName;
	    _lModule.erase(it);
	    _lib.close(modName);
	  }
      }
  }
}
}
