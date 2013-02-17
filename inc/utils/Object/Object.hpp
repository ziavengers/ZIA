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
      size_t connect(const std::string& name, const StockCallback& slot)
      {
	_slots[name][this].push_back(s_slot(slot));
	return _nbConnections;
      }
      #include "build/emit.hpp"
    private:
      struct s_slot
      {
      	s_slot(const StockCallback& c_) : id(_nbConnections++), c(c_) {}
      	size_t id;
      	StockCallback c;
      };
      static std::map< std::string, std::map< Object*, std::list< s_slot > > > _slots;
      static size_t _nbConnections;
    };

  }
}

#endif
