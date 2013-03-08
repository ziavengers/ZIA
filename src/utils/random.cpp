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
    unsigned int Random::get() const
    {
      return ::rand();
    }
    unsigned int Random::get(unsigned int max) const
    {
      return (get() % max);
    }

    unsigned int rand()
    {
      return Singleton< Random >::instance()->get();
    }
    unsigned int rand(unsigned int max)
    {
      return Singleton< Random >::instance()->get(max);
    }

  }
}
