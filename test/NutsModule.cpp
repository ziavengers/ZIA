//
// NutsModule.cpp for hh in /home/nuts/local/ZIA/test
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Mon Mar  4 16:43:38 2013 Rivot Corentin
// Last update Mon Mar  4 16:51:59 2013 Rivot Corentin
//

#include "NutsModule.hh"

zia::module::IModule*	createModule(void)
{
  return new NutsModule;
}

