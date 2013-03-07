//
// NutsModule.cpp for hh in /home/nuts/local/ZIA/test
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Mon Mar  4 16:43:38 2013 Rivot Corentin
// Last update Thu Mar  7 18:48:32 2013 Rivot Corentin
//

#include "NutsModule.hh"

extern "C"
{

  zia::core::module::IModule*	createModule(const std::string& s1, const std::string& s2, const std::map< std::string, std::string >& opt)
  {
    return new NutsModule(s1, s2, opt);
  }

}

