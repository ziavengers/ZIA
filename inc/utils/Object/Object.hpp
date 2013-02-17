#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <map>
#include <string>
#include <list>

#include "utils/bind.hpp"

namespace zia
{
  namespace utils
  {

    class Object
    {
    public:
      virtual ~Object() {}
      void connect(const std::string& name, StockCallback slot)
      {
      	_slots[name].push_back(slot);
      }
      #include "build/emit.hpp"
    private:
      static std::map< std::string, std::list< StockCallback > > _slots;
    };

  }
}

#endif
