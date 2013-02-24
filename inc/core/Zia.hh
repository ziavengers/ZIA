#ifndef ZIA_HH_
#define ZIA_HH_

#include "core/ThreadPool.hh"

namespace zia
{
  namespace core
  {

    class Zia
    {
    public:
      Zia(int, int, int);
    private:
      ThreadPool _pool;
    };

  }
}

#endif
