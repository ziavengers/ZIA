#ifndef CORE_MODULE_MODULEMANAGEMENT_HH_
#define CORE_MODULE_MODULEMANAGEMENT_HH_

#include <list>
#include <string>

#include "Module.hh"
#include "utils/Exception.hpp"
#include "utils/Library.hpp"

namespace zia
{
  namespace core
  {
    namespace module
    {

      /*

	Contient les modules charges depuis un nom de fichier.

      */

      class	ModuleManagement
      {
      public:
	CLASS_EXCEPTION("zia::core::module::ModuleManagement: ");

      public:

	ModuleManagement();
	~ModuleManagement();

	/* Probablement inutile */
	void	loadModule(IModule*) throw (Exception);

	/*

	  Charge une librairie dynamique.
	  - extraction de createModule.
	  - et stockage du IModule* creer dans la liste des modules.

	*/

	void	loadModule(const std::string& path, const std::string& sigInput, const std::string& sigOutput, const std::map< std::string, std::string >& args, const std::string& name = "") throw (Exception);

	/* Idem probablement inutile*/
	void	unloadModule(IModule*) throw (Exception);


	void	unloadModule(const std::string& modName)  throw (Exception);

      private:    
	utils::Library			_lib;
	std::list< IModule* >	_lModule;
      };

    }
  }
}


#endif
