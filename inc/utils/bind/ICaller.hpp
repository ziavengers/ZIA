#ifndef ICALLER_HPP_
#define ICALLER_HPP_

namespace zia {
  namespace utils {

class ICaller
{
public:
  virtual ~ICaller() {}
  virtual const std::string& paramTypeNames() const = 0;
};

  }
}

#endif
