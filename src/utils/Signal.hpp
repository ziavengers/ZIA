//
// Signal.hpp for hh in /home/nuts/local/ZIA/src
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Tue Jan 29 20:22:06 2013 Rivot Corentin
// Last update Wed Jan 30 12:42:06 2013 Rivot Corentin
//

#ifndef SIGNAL_HPP_
#define SIGNAL_HPP_


#include <map>
#include <string>
#include "bind/Caller.hpp"

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

#endif
