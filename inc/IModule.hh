//
// IModule.hh for hh in /home/nuts/local/ZIA/src
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Thu Feb  7 13:29:51 2013 Rivot Corentin
// Last update Fri Feb  8 12:16:08 2013 Rivot Corentin
//

#ifndef IMODULE_HH_
#define IMODULE_HH_

#include <string>

namespace zia
{
  namespace module
  {

    class IModule
    {
    public:
      ~IModule() { }

      /*
	Module must have a name!
       */

      virtual void	name(const std::string&) = 0;
      virtual const std::string&	name() const = 0;

      virtual void	version(int major, int minor) = 0;

      private:
    };

    extern "C"
    {
      
      /* Module must implement this function with this name! */
      IModule*	createModule(void);            
      
    }


  }
}

#endif
