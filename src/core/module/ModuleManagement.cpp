#include "core/module/ModuleManagement.hh"
#include "utils/Logger.hpp"

namespace zia
{
  namespace core
  {
    namespace module
    {

      ModuleManagement::ModuleManagement()
      {
      }

      ModuleManagement::~ModuleManagement()
      {
    
      }

      void	ModuleManagement::loadModule(IModule* m) throw (Exception)
      {
	if (!m)
	  throw Exception("loadModule: null pointer");
	LOG_INFO << "Add module named " << m->name() << std::endl;
	_lModule.push_back(m);
      }

      void	ModuleManagement::loadModule(const std::string& path, const std::string& name) throw (Exception)
      {
	try
	  {
	    if (name.empty())
	      _lib.add(path);
	    else
	      _lib.add(path, name);
	    IModule::t_createModule fptr;
	    fptr = _lib.getFunction< IModule::t_createModule >(path, "createModule");
	    IModule* ty = fptr("", "", std::map< std::string, std::string >());
	    _lModule.push_back(ty);
	    LOG_INFO << "Load module named : " <<  path << std::endl;
	  }
	catch (utils::Exception& e)
	  {
	    throw (e);
	  }
	catch (...)
	  {
	    throw Exception("loadModule: Unknow error catched");
	  }
      }

    void	ModuleManagement::unloadModule(IModule* m) throw (Exception)
      {
	if (!m)
	  throw Exception("unloadModule: null pointer");
	unloadModule(m->name());
      }

      void	ModuleManagement::unloadModule(const std::string& modName) throw (Exception)
      {
	std::list< IModule* >::iterator	it;

	for (it = _lModule.begin(); it != _lModule.end(); ++it)
	  {
	    if ((*it)->name() == modName)
	      {
		LOG_INFO << "Unload module named : " << modName << std::endl;
		_lModule.erase(it);
		_lib.close(modName);
		break;
	      }
	  }
      }

    }
  }
}
