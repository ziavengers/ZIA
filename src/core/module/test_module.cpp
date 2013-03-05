#include <core/module/Module.hh>

int	main(int ac, char **av)
{
  zia::log.severity(zia::utils::Logger::DEBUG);

  zia::core::module::ModuleManagement mg;

  /*
    loading module from is path
   */

  if (ac > 2)
    mg.loadModule(av[1]);
  else
    mg.loadModule("../../../test/libNutsModule.so");

  /* 
     unload it frim his name
   */
  mg.unloadModule("NutsModule");
  return 0;
}
