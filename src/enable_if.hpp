//
// enable_if.hpp for hh in /home/nuts/local/ZIA/src
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Fri Jan 25 17:26:08 2013 Rivot Corentin
// Last update Fri Jan 25 17:28:08 2013 Rivot Corentin
//

#ifndef ENABLEIF_HPP_
#define ENABLEIF_HPP_

template < bool C, typename T=void* >

struct enable_if
{
  typedef T	Type;
};

template < typename T >

struct enable_if < 0, T >
{
};

#endif
