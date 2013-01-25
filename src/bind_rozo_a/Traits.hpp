#ifndef _TRAITS_HPP_
#define _TRAITS_HPP_

#include "TypeList.hpp"

struct Traits0
{
  typedef TypeList0 Type;
};

template < typename P1 >
struct Traits1
{
  typedef typename GetType < P1 >::Type Type_Param1;
  typedef TypeList1 < Type_Param1 > Type;
};

template < typename P1, typename P2 >
struct Traits2
{
  typedef typename GetType < P1 >::Type Type_Param1;
  typedef typename GetType < P2 >::Type Type_Param2;
  typedef TypeList2 < Type_Param1, Type_Param2 > Type;
};

template < typename P1, typename P2, typename P3 >
struct Traits3
{
  typedef typename GetType < P1 >::Type Type_Param1;
  typedef typename GetType < P2 >::Type Type_Param2;
  typedef typename GetType < P3 >::Type Type_Param3;
  typedef TypeList3 < Type_Param1, Type_Param2, Type_Param3 > Type;
};

template < typename P1, typename P2, typename P3, typename P4 >
struct Traits4
{
  typedef typename GetType < P1 >::Type Type_Param1;
  typedef typename GetType < P2 >::Type Type_Param2;
  typedef typename GetType < P3 >::Type Type_Param3;
  typedef typename GetType < P4 >::Type Type_Param4;
  typedef TypeList4 < Type_Param1, Type_Param2, Type_Param3, Type_Param4 > Type;
};

template < typename P1, typename P2, typename P3, typename P4, typename P5 >
struct Traits5
{
  typedef typename GetType < P1 >::Type Type_Param1;
  typedef typename GetType < P2 >::Type Type_Param2;
  typedef typename GetType < P3 >::Type Type_Param3;
  typedef typename GetType < P4 >::Type Type_Param4;
  typedef typename GetType < P5 >::Type Type_Param5;
  typedef TypeList5 < Type_Param1, Type_Param2, Type_Param3, Type_Param4, Type_Param5 > Type;
};

template < typename P1, typename P2, typename P3, typename P4, typename P5, typename P6 >
struct Traits6
{
  typedef typename GetType < P1 >::Type Type_Param1;
  typedef typename GetType < P2 >::Type Type_Param2;
  typedef typename GetType < P3 >::Type Type_Param3;
  typedef typename GetType < P4 >::Type Type_Param4;
  typedef typename GetType < P5 >::Type Type_Param5;
  typedef typename GetType < P6 >::Type Type_Param6;
  typedef TypeList6 < Type_Param1, Type_Param2, Type_Param3, Type_Param4, Type_Param5, Type_Param6 > Type;
};

#endif
