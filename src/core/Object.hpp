#ifndef OBJECT_HPP_
#define OBJECT_HPP_

namespace zia
{
  namespace core
  {

#include <map>
#include <string>
#include "src/utils/bind.hpp"

    class Signal
    {
    public:
      Signal() { }
      ~Signal() { }

      template < typename T >

      void	connect(const std::string& s, T *func)
      {
	_calling[s] = new StockCallback(bind(func));
      }

      template < typename T >

      void	connect(const std::string& s, int (T::*func)(), T* obj)
      {
	_calling[s] = new StockCallback(bind< int >(func, *obj));
      }  
  
      void	emit(const std::string& s)
      {
	(*_calling[s])();
      }

    protected:
      std::map< std::string, StockCallback* >	_calling;


    private:
    };

  }
}

#endif
