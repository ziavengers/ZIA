#ifndef UTILS_ENABLEIF_HPP_
#define UTILS_ENABLEIF_HPP_


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
