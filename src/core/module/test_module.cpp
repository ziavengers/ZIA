#include "core/module/ModuleManagement.hh"
#include "core/Object.hpp"
#include "utils/bind.hpp"
#include "utils/Logger.hpp"

#include <iostream>

#include <exception>

class Toto : public zia::core::Object
{
public:
  Toto() {
  }
};

int	main(int ac, char **av)
{
  zia::utils::Singleton < zia::utils::Logger >::instance(new zia::utils::Logger("out.log", zia::utils::Logger::DEBUG));

  zia::core::module::ModuleManagement mg;

zia::utils::Singleton< zia::core::ThreadPool >::instance(new zia::core::ThreadPool);
zia::utils::Singleton< zia::core::ThreadPool >::instance()->start();
  /*
    loading module from is path
   */

  if (ac > 2)
    mg.loadModule(av[1], "in", "out", std::map< std::string, std::string >());
  else
    mg.loadModule("../../../bin/modules/NutsModule.mod", "in", "out", std::map< std::string, std::string >());


  Toto t;
  t.emit("test");
while(1);
  /* 
     unload it from his name
   */
  mg.unloadModule("NutsModule");
  return 0;
}
