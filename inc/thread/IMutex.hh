#ifndef IMUTEX_HH_
#define IMUTEX_HH_

#include "utils/NonCopyable.hh"

namespace zia
{
  namespace thread
  {
 
    class IMutex : public NonCopyable
    {
    public:
      virtual ~Mutex() { }

      virtual void	lock() = 0;
      virtual void	unlock() = 0;
      virtual bool	trylock() = 0;
      
    };
    
  }
}

#endif
