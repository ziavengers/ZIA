#include "core/module/Module.hh"

namespace zia
{
  namespace core
  {
    namespace module
    {

      AModule::AModule(const std::string& sigInput, const std::string& sigOutput) :
	_sigInput(sigInput), _sigOutput(sigOutput)
      {}

    }
  }
}
