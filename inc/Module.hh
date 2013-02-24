#ifndef MODULE_HH_
#define MODULE_HH_

#include <list>
#include <string>

#include "IModule.hh"
#include "utils/Logger.hh"
#include "utils/Exception.hpp"
#include "utils/Library.hh"

namespace zia
{
namespace module
{

  /*

    Contient les modules charges depuis un nom de fichier.

   */

  class	ModuleManagement
  {
  public:
    ModuleManagement();
    ~ModuleManagement();

    /* Probablement inutile */
    void	loadModule(IModule*) throw (utils::Exception);

    /*

      Charge une librairie dynamique.
      - extraction de createModule.
      - et stockage du IModule* creer dans la liste des modules.

     */

    void	loadModule(const std::string& path) throw (utils::Exception);

    /* Idem probablement inutile*/
    void	unloadModule(IModule*) throw (utils::Exception);


    void	unloadModule(const std::string& modName)  throw (utils::Exception);

  private:    
    utils::Library			_lib;
    std::list< IModule* >	_lModule;
  };

}
}

#endif
