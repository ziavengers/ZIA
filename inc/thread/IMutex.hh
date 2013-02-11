#ifndef IMUTEX_HH_
#define IMUTEX_HH_

namespace zia
{
  namespace thread
  {
 
    class IMutex
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
