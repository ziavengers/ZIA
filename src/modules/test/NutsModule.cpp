#include "NutsModule.hh"

extern "C"
{

  zia::core::module::IModule*	createModule(const std::string& s1, const std::string& s2, const std::map< std::string, std::string >&)
  {
    return new NutsModule(s1, s2);
  }

}

