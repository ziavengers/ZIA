#ifndef NUTSMODULE_HH_
#define NUTSMODULE_HH_


#include "core/module/Module.hh"
#include "utils/bind.hpp"

#include <iostream>

class	NutsModule : public zia::core::module::AModule
{
public:
  NutsModule(const std::string& s1, const std::string& s2) : AModule(s1, s2, "NutsModule") {
    this->connect(s1, zia::utils::bind(&NutsModule::test, *this));
  }

  ~NutsModule() { }
  
  void	test()
  {
    std::cout << "TEST called" << std::endl;
  }

};

#endif

