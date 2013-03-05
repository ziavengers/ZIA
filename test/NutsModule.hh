//
// NutsModule.hh for hh in /home/nuts/local/ZIA/test
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Mon Mar  4 16:44:17 2013 Rivot Corentin
// Last update Tue Mar  5 10:42:40 2013 Rivot Corentin
//

#ifndef NUTSMODULE_HH_
#define NUTSMODULE_HH_


#include "IModule.hh"

#include <iostream>

class	NutsModule : public zia::module::AModule
{
public:
  NutsModule() { _name = "NutsModule"; }
  ~NutsModule() { }
  
  void	name(const std::string& name) { _name = name; }
  const std::string&        name() const { return _name; }
  void	version(int major, int minor) { _minor = minor; _major = major; };

};


#endif

