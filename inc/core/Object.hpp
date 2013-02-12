#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <map>
#include <string>
#include <list>
#include "utils/bind.hpp"
#include "utils/StockCallback.hpp"

namespace zia
{
  namespace core
  {

    class Object
    {
    public:
      Object() {}
      ~Object() {}

      template < typename T >
      void connect(const std::string& s, T *func)
      {
	_calling[s].push_back(new utils::StockCallback(utils::bind(func)));
      }

      template < typename ReturnType, typename Obj >
      void connect(const std::string& s, ReturnType (Obj::*func)(), Obj* obj)
      {
	_calling[s].push_back(new utils::StockCallback(utils::bind(func, *obj)));
      }

      template < typename ReturnType, typename Obj, typename P1 >
      void connect(const std::string& s, ReturnType (Obj::*func)(P1), Obj* obj, P1 p)
      {
	_calling[s].push_back(new utils::StockCallback(utils::bind(func, *obj, p)));
      }
  
      void	emit(const std::string& s)
      {
	std::list< utils::StockCallback* >::iterator	it;
	for (it = _calling[s].begin(); it != _calling[s].end(); ++it)
	  (*it)->operator()();
      }

    protected:
      static std::map< std::string, std::list < utils::StockCallback* > >	_calling;
    };

    std::map< std::string, std::list < utils::StockCallback* > >	Object::_calling;

  }
}

#endif
