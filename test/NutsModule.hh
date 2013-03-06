//
// NutsModule.hh for hh in /home/nuts/local/ZIA/test
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Mon Mar  4 16:44:17 2013 Rivot Corentin
// Last update Tue Mar  5 12:04:34 2013 Rivot Corentin
//

#ifndef NUTSMODULE_HH_
#define NUTSMODULE_HH_


#include <core/module/IModule.hh>
#include <utils/bind.hpp>

#include <iostream>

class	NutsModule : public zia::core::module::AModule
{
public:
  NutsModule() { 
    _name = "NutsModule";
    this->connect("test", zia::utils::bind(&NutsModule::test, *this));
  }

  ~NutsModule() { }
  
  void	test()
  {
    std::cout << "TEST called" << std::endl;
  }

  void	name(const std::string& name) { _name = name; }
  const std::string&        name() const { return _name; }
  void	version(int major, int minor) { _minor = minor; _major = major; };

};

#endif

