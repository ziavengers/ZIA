#include <stdlib.h>
#include <time.h>

#include "utils/random.hh"
#include "utils/Singleton.hpp"

namespace zia
{
  namespace utils
  {

    Random::Random()
    {
      srand(time(0));
    }
    int Random::get() const
    {
      return rand();
    }

    int rand()
    {
      return Singleton< Random >::instance()->get();
    }

  }
}
