#include "core/Object.hpp"

namespace zia
{
  namespace core
  {

    std::map< std::string, std::map< Object*, std::list< Object::s_slot > > > Object::_slots;
    size_t Object::_nbConnections = 0;

  }
}