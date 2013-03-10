#ifndef CORE_OBJECT_OBJECT_HPP_
#define CORE_OBJECT_OBJECT_HPP_

#include <map>
#include <string>
#include <list>

#include "utils/bind.hpp"
#include "thread/Mutex.hh"
#include "thread/Locker.hh"
#include "utils/Singleton.hpp"
#include "core/ThreadPool.hh"
#include "utils/Exception.hpp"

namespace zia
{
  namespace core
  {

    namespace Signal
    {
      CLASS_EXCEPTION("zia::core::Signal: ");
    }

    class Object
    {
    public:
      Object() : _manageSlotMutex(), _sender(0), _context("*"), _toDelete(false)
      {}
      virtual ~Object()
      {
	disconnect();
      }
      TYPENAME(zia::core::Object);

      size_t connect(const std::string& name, const utils::StockCallback& slot, const std::string& context = "*")
      {
	thread::Locker lock(_slotsMutex);
	_slots[name][this].push_back(s_slot(slot, context));
	return _nbConnections;
      }
      void disconnect()
      {
	thread::Locker lock(_slotsMutex);
	std::map< std::string, std::map< Object*, std::list < s_slot > > >::iterator itm;
	for (itm = _slots.begin(); itm != _slots.end(); ++itm)
	  disconnect(itm);
      }
      void disconnect(const std::string& name, size_t id)
      {
	thread::Locker lock(_slotsMutex);
	std::map< std::string, std::map< Object*, std::list < s_slot > > >::iterator itm;
	itm = _slots.find(name);
	if (itm != _slots.end())
	  disconnect(itm, id);
      }
      void disconnect(size_t id)
      {
	thread::Locker lock(_slotsMutex);
	std::map< std::string, std::map< Object*, std::list < s_slot > > >::iterator itm;
	for (itm = _slots.begin(); itm != _slots.end(); ++itm)
	  disconnect(itm, id);
      }
      void disconnect(const std::string& name)
      {
	thread::Locker lock(_slotsMutex);
	std::map< std::string, std::map< Object*, std::list < s_slot > > >::iterator itm;
	itm = _slots.find(name);
	if (itm != _slots.end())
	  disconnect(itm);
      }

      void deleteLater()
      {
	disconnect();
	zia::utils::Singleton< zia::core::ThreadPool >::instance()->push(this, this, "*", utils::bind(&Object::_delete, *this));
      }

      void manageSlot(Object* sender, const std::string& context, utils::StockCallback& c)
      {
	{
	  thread::Locker lock(_manageSlotMutex);
	  _sender = sender;
	  _context = context;
	  c();
	}
	if (_toDelete)
	  delete this;
      }

      #include "build/emit.hpp"

    protected:
      Object* sender() const
      {
	return _sender;
      }
      const std::string& context() const
      {
	return _context;
      }

    private:
      thread::Mutex _manageSlotMutex;
      Object* _sender;
      std::string _context;
      bool _toDelete;

      struct s_slot
      {
      	s_slot(const utils::StockCallback& c_, const std::string& context_) : id(_nbConnections++), c(c_), context(context_) {}
      	size_t id;
      	utils::StockCallback c;
	std::string context;
      };
      static std::map< std::string, std::map< Object*, std::list< s_slot > > > _slots;
      static thread::Mutex _slotsMutex;
      static size_t _nbConnections;

      void _delete()
      {
        _toDelete = true;
      }


      inline void disconnect(const std::map< std::string, std::map< Object*, std::list < s_slot > > >::iterator& itm)
      {
	itm->second.erase(this);
      }
      inline void disconnect(const std::map< std::string, std::map< Object*, std::list < s_slot > > >::iterator& itm, size_t id)
      {
	std::map< Object*, std::list < s_slot > >::iterator ito;
	std::list < s_slot >::iterator it;
	ito = itm->second.find(this);
	if (ito != itm->second.end())
	  for (it = ito->second.begin(); it != ito->second.end(); ++it)
	    if (it->id == id)
	      {
		ito->second.erase(it);
		return ;
	      }
      }
    };

  }
}

#endif
