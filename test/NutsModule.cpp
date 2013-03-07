//
// NutsModule.cpp for hh in /home/nuts/local/ZIA/test
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Mon Mar  4 16:43:38 2013 Rivot Corentin
// Last update Thu Mar  7 22:01:00 2013 Antoine Rozo
//

#include "NutsModule.hh"

extern "C"
{

  zia::core::module::IModule*	createModule(const std::string& s1, const std::string& s2, const std::map< std::string, std::string >&)
  {
    return new NutsModule(s1, s2);
  }

}

