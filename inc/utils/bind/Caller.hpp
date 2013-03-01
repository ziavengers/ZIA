#ifndef CALLER_HPP_
#define CALLER_HPP_

#include "ICaller.hpp"
#include "build/ParamCaller.hpp"

namespace zia {
  namespace utils {

template <typename ReturnType, typename Callable, typename List>
class Caller : public ParamCaller< List >
{
public:
  Caller(Callable callable, List list, const std::string& paramTypeNames = "") : ParamCaller< List >(list, paramTypeNames), _callable(callable) {}
  ReturnType operator()()
  {
    return this->_list(TypeTraits<ReturnType>(), _callable, this->_list);
  }
protected:
  Callable _callable;
};

  }
}
#endif
