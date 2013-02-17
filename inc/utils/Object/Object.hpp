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
      virtual ~Object()
      {
	disconnect();
      }
      size_t connect(const std::string& name, const StockCallback& slot)
      {
	_slots[name][this].push_back(s_slot(slot));
	return _nbConnections;
      }
      void disconnect()
      {
	std::map< std::string, std::map< Object*, std::list < s_slot > > >::iterator itm;
	for (itm = _slots.begin(); itm != _slots.end(); ++itm)
	  itm->second.erase(this);
      }
      // Factoriser
      void disconnect(const std::string& name, size_t id)
      {
	std::map< std::string, std::map< Object*, std::list < s_slot > > >::iterator itm;
	std::map< Object*, std::list < s_slot > >::iterator ito;
	std::list < s_slot >::iterator it;
	itm = _slots.find(name);
	if (itm != _slots.end())
	  {
	    ito = itm->second.find(this);
	    if (ito != itm->second.end())
	      for (it = ito->second.begin(); it != ito->second.end(); ++it)
		if (it->id == id)
		  {
		    ito->second.erase(it);
		    return ;
		  }
	  }
      }
      void disconnect(size_t id)
      {
	std::map< std::string, std::map< Object*, std::list < s_slot > > >::iterator itm;
	std::map< Object*, std::list < s_slot > >::iterator ito;
	std::list < s_slot >::iterator it;
	for (itm = _slots.begin(); itm != _slots.end(); ++itm)
	  {
	    ito = itm->second.find(this);
	    if (ito != itm->second.end())
	      for (it = ito->second.begin(); it != ito->second.end(); ++it)
		if (it->id == id)
		  {
		    ito->second.erase(it);
		    return ;
		  }
	  }
      }
      void disconnect(const std::string& name)
      {
	std::map< std::string, std::map< Object*, std::list < s_slot > > >::iterator itm;
	itm = _slots.find(name);
	if (itm != _slots.end())
	  {
	    itm->second.erase(this);
	  }
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
