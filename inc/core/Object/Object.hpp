#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <map>
#include <string>
#include <list>

#include "utils/bind.hpp"
#include "thread/Mutex.hh"
#include "thread/Locker.hh"
#include "utils/Singleton.hpp"
#include "core/ThreadPool.hh"

namespace zia
{
  namespace core
  {

    class Object
    {
    public:
      Object() : _manageSlotMutex(), _sender(0), _toDelete(false)
      {}
      virtual ~Object()
      {
	disconnect();
      }
      size_t connect(const std::string& name, const utils::StockCallback& slot)
      {
	thread::Locker lock(_slotsMutex);
	_slots[name][this].push_back(s_slot(slot));
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
	zia::utils::Singleton< zia::core::ThreadPool >::instance()->push(this, this, utils::bind(&Object::_delete, *this));
      }

      void manageSlot(Object* sender, utils::StockCallback& c)
      {
	{
	  thread::Locker lock(_manageSlotMutex);
	  _sender = sender;
	  c();
	}
	if (_toDelete)
	  delete this;
      }

      #include "build/emit.hpp"

    protected:
      Object* sender()
      {
	return _sender;
      }

    private:
      thread::Mutex _manageSlotMutex;
      Object* _sender;
      bool _toDelete;

      struct s_slot
      {
      	s_slot(const utils::StockCallback& c_) : id(_nbConnections++), c(c_) {}
      	size_t id;
      	utils::StockCallback c;
      };
      static std::map< std::string, std::map< Object*, std::list< s_slot > > > _slots;
      static thread::Mutex _slotsMutex;
      static size_t _nbConnections;

      // static void _delete(Object* o)
      // {
      //   delete o;
      // }

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
