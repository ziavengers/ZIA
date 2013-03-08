#ifndef NUTSMODULE_HH_
#define NUTSMODULE_HH_


#include "core/module/Module.hh"
#include "utils/bind.hpp"

#include <iostream>

class	NutsModule : public zia::core::module::AModule
{
public:
  // NutsModule(const std::string& s1, const std::string& s2) : AModule(s1, s2) {
  //   _name = "NutsModule";
  NutsModule(const std::string& s1, const std::string& s2) : AModule(s1, s2, "NutsModule") {
    // this->connect("test", zia::utils::bind(&NutsModule::test, *this));
    this->connect(s1, zia::utils::bind(&NutsModule::test, *this));
  }

  ~NutsModule() { }
  
  void	test()
  {
    std::cout << "TEST called" << std::endl;
  }

  // void	name(const std::string& name) { _name = name; }
  // const std::string&        name() const { return _name; }
  // void	version(int major, int minor) { _minor = minor; _major = major; };

};

#endif

