//
// NutsModule.cpp for hh in /home/nuts/local/ZIA/test
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Mon Mar  4 16:43:38 2013 Rivot Corentin
// Last update Tue Mar  5 10:29:10 2013 Rivot Corentin
//

#include "NutsModule.hh"

extern "C"
{

zia::module::IModule*	createModule(void)
{
  return new NutsModule;
}

}

