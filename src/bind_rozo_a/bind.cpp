#include "Caller.hpp"
#include "Traits.hpp"

template < typename ReturnType >
Caller < ReturnType, ReturnType(*)(), typename Traits0::Type >
bind(ReturnType(*f)())
{
  typedef TypeList0 ListType;
  ListType l;
  return Caller < ReturnType, ReturnType(*)(), ListType > (f, l);
}

template < typename ReturnType, typename X1,
	   typename Param1 >
Caller < ReturnType, ReturnType(*)(X1), typename Traits1 < Param1 >::Type >
bind(ReturnType(*f)(X1), Param1 p1)
{
  typedef typename GetType < Param1 >::Type P1;
  typedef TypeList1 < P1 > ListType;
  ListType l(p1);
  return Caller < ReturnType, ReturnType(*)(X1), ListType > (f, l);
}

template < typename ReturnType, typename X1, typename X2,
	   typename Param1, typename Param2 >
Caller < ReturnType, ReturnType(*)(X1, X2), typename Traits2 < Param1, Param2 >::Type >
bind(ReturnType(*f)(X1, X2), Param1 p1, Param2 p2)
{
  typedef typename GetType < Param1 >::Type P1;
  typedef typename GetType < Param2 >::Type P2;
  typedef TypeList2 < P1, P2 > ListType;
  ListType l(p1, p2);
  return Caller < ReturnType, ReturnType(*)(X1, X2), ListType > (f, l);
}

template < typename ReturnType, typename X1, typename X2, typename X3,
	   typename Param1, typename Param2, typename Param3 >
Caller < ReturnType, ReturnType(*)(X1, X2, X3), typename Traits3 < Param1, Param2, Param3 >::Type >
bind(ReturnType(*f)(X1, X2, X3), Param1 p1, Param2 p2, Param3 p3)
{
  typedef typename GetType < Param1 >::Type P1;
  typedef typename GetType < Param2 >::Type P2;
  typedef typename GetType < Param3 >::Type P3;
  typedef TypeList3 < P1, P2, P3 > ListType;
  ListType l(p1, p2, p3);
  return Caller < ReturnType, ReturnType(*)(X1, X2, X3), ListType > (f, l);
}

template < typename ReturnType, typename X1, typename X2, typename X3, typename X4,
	   typename Param1, typename Param2, typename Param3, typename Param4 >
Caller < ReturnType, ReturnType(*)(X1, X2, X3, X4), typename Traits4 < Param1, Param2, Param3, Param4 >::Type >
bind(ReturnType(*f)(X1, X2, X3, X4), Param1 p1, Param2 p2, Param3 p3, Param4 p4)
{
  typedef typename GetType < Param1 >::Type P1;
  typedef typename GetType < Param2 >::Type P2;
  typedef typename GetType < Param3 >::Type P3;
  typedef typename GetType < Param4 >::Type P4;
  typedef TypeList4 < P1, P2, P3, P4 > ListType;
  ListType l(p1, p2, p3, p4);
  return Caller < ReturnType, ReturnType(*)(X1, X2, X3, X4), ListType > (f, l);
}

template < typename ReturnType, typename X1, typename X2, typename X3, typename X4, typename X5,
	   typename Param1, typename Param2, typename Param3, typename Param4, typename Param5 >
Caller < ReturnType, ReturnType(*)(X1, X2, X3, X4, X5), typename Traits5 < Param1, Param2, Param3, Param4, Param5 >::Type >
bind(ReturnType(*f)(X1, X2, X3, X4, X5), Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5)
{
  typedef typename GetType < Param1 >::Type P1;
  typedef typename GetType < Param2 >::Type P2;
  typedef typename GetType < Param3 >::Type P3;
  typedef typename GetType < Param4 >::Type P4;
  typedef typename GetType < Param5 >::Type P5;
  typedef TypeList5 < P1, P2, P3, P4, P5 > ListType;
  ListType l(p1, p2, p3, p4, p5);
  return Caller < ReturnType, ReturnType(*)(X1, X2, X3, X4, X5), ListType > (f, l);
}

template < typename ReturnType, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6,
	   typename Param1, typename Param2, typename Param3, typename Param4, typename Param5, typename Param6 >
Caller < ReturnType, ReturnType(*)(X1, X2, X3, X4, X5, X6), typename Traits6 < Param1, Param2, Param3, Param4, Param5, Param6 >::Type >
bind(ReturnType(*f)(X1, X2, X3, X4, X5, X6), Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6)
{
  typedef typename GetType < Param1 >::Type P1;
  typedef typename GetType < Param2 >::Type P2;
  typedef typename GetType < Param3 >::Type P3;
  typedef typename GetType < Param4 >::Type P4;
  typedef typename GetType < Param5 >::Type P5;
  typedef typename GetType < Param6 >::Type P6;
  typedef TypeList6 < P1, P2, P3, P4, P5, P6 > ListType;
  ListType l(p1, p2, p3, p4, p5, p6);
  return Caller < ReturnType, ReturnType(*)(X1, X2, X3, X4, X5, X6), ListType > (f, l);
}

// int addition(int a, int b, int c)
int addition(int a, int b, int c, int d, int e, int f)
{
  return (a + b + c + d + e + f);
}

#include <iostream>

int main()
{
  // Caller a = bind(addition, 1, 2, 3);
  std::cout << bind(addition, 1, 2, 3, 4, 5, 6)() << std::endl;
}
