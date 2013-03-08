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
      unsigned int get() const;
      unsigned int get(unsigned int) const;
    };

    unsigned int rand();
    unsigned int rand(unsigned int);

  }
}

#endif
