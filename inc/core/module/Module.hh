#ifndef CORE_MODULE_MODULE_HH_
#define CORE_MODULE_MODULE_HH_

#include <string>
#include "core/Object.hpp"

namespace zia
{
  namespace core
  {
    namespace module
    {

      class IModule
      {
      public:
	virtual ~IModule() { }

	/*
	  Module must have a name!
	*/

	virtual void	name(const std::string&) = 0;
	virtual const std::string&	name() const = 0;

	typedef IModule* (*t_createModule)(const std::string&, const std::string&, const std::map< std::string, std::string >&);

      };

      class AModule : public IModule, public zia::core::Object
      {
      public:
	AModule(const std::string& sigInput, const std::string& sigOutput, const std::string& name = "");
	virtual ~AModule() { }
	TYPENAME(zia::core::module::Module);

	void	name(const std::string&);
	const std::string&	name() const;

      protected:
	std::string	_name;
	std::string	_sigInput;
	std::string	_sigOutput;

      };

    }
  }
}

#endif
