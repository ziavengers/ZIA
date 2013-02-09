#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <map>
#include <string>
#include "utils/bind.hpp"

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
      void connect(const std::string&, T)
      {}

      // void	connect(const std::string& s, T *func)
      // {
      // 	_calling[s] = new StockCallback(bind(func));
      // }

      // template < typename T >

      // void	connect(const std::string& s, int (T::*func)(), T* obj)
      // {
      // 	_calling[s] = new StockCallback(bind< int >(func, *obj));
      // }  
  
      // void	emit(const std::string& s)
      // {
      // 	(*_calling[s])();
      // }

      void emit(const std::string&)
      {}

    protected:
      std::map< std::string, StockCallback* >	_calling;
    };

  }
}

#endif
