#ifndef RANDOM_HH_
#define RANDOM_HH_

namespace zia
{
  namespace utils
  {

    class Random
    {
    public:
      Random();
      int get() const;
    };

    int rand();

  }
}

#endif
