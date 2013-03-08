#include "core/module/Module.hh"

namespace zia
{
  namespace core
  {
    namespace module
    {

      AModule::AModule(const std::string& sigInput, const std::string& sigOutput, const std::string& name) :
	_name(name), _sigInput(sigInput), _sigOutput(sigOutput)
      {}

      const std::string& AModule::name() const
      {
	return _name;
      }

      void AModule::name(const std::string& name)
      {
	_name = name;
      }

    }
  }
}
