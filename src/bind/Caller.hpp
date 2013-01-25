/*
** Caller.hpp for  in /home/nuts/local/ZIA/src/bind
** 
** Made by 
** Login   <nuts@epitech.net>
** 
** Started on  Thu Jan 24 21:43:28 2013 
// Last update Fri Jan 25 12:55:25 2013 Rivot Corentin
*/

#ifndef		CALLER_HPP_
# define	CALLER_HPP_

#include "TypeList.hpp"

template < typename ReturnType, typename Callable, typename List >

class Caller
{
public:
  Caller(Callable c, List l) : _callable(c), _list(l) { }

  ReturnType	operator()()
  {
    TypeTraits< ReturnType >	t;
    return _list.operator()(t, _callable, _list);
  }
private:
  Callable	_callable;
  List		_list;
};

template < typename ReturnType >

Caller< ReturnType, ReturnType(*)(), typename Traits0::Type >
bind(ReturnType(*f)())
{
  TypeList0 l;
  return Caller< ReturnType, ReturnType(*)(), TypeList0 >(f, l);
}

template < typename ReturnType, typename X1, typename Param1 >

Caller< ReturnType, ReturnType(*)(X1), typename Traits1< Param1 >::Type >
bind(ReturnType(*f)(X1), Param1 p1)
{
  typedef typename GetType< Param1 >::Type	P1;
  typedef TypeList1< P1 >	ListType;
  ListType l(p1);
  return Caller< ReturnType, ReturnType(*)(X1), ListType >(f, l);
}


template < typename ReturnType, typename X1, typename X2, typename Param1, typename Param2 >

Caller< ReturnType, ReturnType(*)(X1, X2), typename Traits2< Param1, Param2 >::Type >
bind(ReturnType(*f)(X1, X2), Param1 p1, Param2 p2)
{
  typedef typename GetType< Param1 >::Type	P1;
  typedef typename GetType< Param2 >::Type	P2;
  typedef TypeList2< P1, P2 >	ListType;
  ListType l(p1, p2);
  return Caller< ReturnType, ReturnType(*)(X1, X2), ListType >(f, l);
}

template < typename ReturnType, typename X1, typename X2, typename X3, typename Param1, typename Param2, typename Param3 >

Caller< ReturnType, ReturnType(*)(X1, X2, X3), typename Traits3< Param1, Param2, Param3 >::Type >
bind(ReturnType(*f)(X1, X2, X3), Param1 p1, Param2 p2, Param3 p3)
{
  typedef typename GetType< Param1 >::Type	P1;
  typedef typename GetType< Param2 >::Type	P2;
  typedef typename GetType< Param3 >::Type	P3;
  typedef TypeList3< P1, P2, P3 >	ListType;
  ListType l(p1, p2, p3);
  return Caller< ReturnType, ReturnType(*)(X1, X2, X3), ListType >(f, l);
}


template < typename ReturnType, typename X1, typename X2, typename X3, typename X4, typename Param1, typename Param2, typename Param3, typename Param4 >

Caller< ReturnType, ReturnType(*)(X1, X2, X3, X4), typename Traits4< Param1, Param2, Param3, Param4 >::Type >
bind(ReturnType(*f)(X1, X2, X3, X4), Param1 p1, Param2 p2, Param3 p3, Param4 p4)
{
  typedef typename GetType< Param1 >::Type	P1;
  typedef typename GetType< Param2 >::Type	P2;
  typedef typename GetType< Param3 >::Type	P3;
  typedef typename GetType< Param4 >::Type	P4;
  typedef TypeList4< P1, P2, P3, P4 >	ListType;
  ListType l(p1, p2, p3, p4);
  return Caller< ReturnType, ReturnType(*)(X1, X2, X3, X4), ListType >(f, l);
}


template < typename ReturnType, typename X1, typename X2, typename X3, typename X4, typename X5, typename Param1, typename Param2, typename Param3, typename Param4, typename Param5 >

Caller< ReturnType, ReturnType(*)(X1, X2, X3, X4, X5), typename Traits5< Param1, Param2, Param3, Param4, Param5 >::Type >
bind(ReturnType(*f)(X1, X2, X3, X4, X5), Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5)
{
  typedef typename GetType< Param1 >::Type	P1;
  typedef typename GetType< Param2 >::Type	P2;
  typedef typename GetType< Param3 >::Type	P3;
  typedef typename GetType< Param4 >::Type	P4;
  typedef typename GetType< Param5 >::Type	P5;
  typedef TypeList5< P1, P2, P3, P4, P5 >	ListType;
  ListType l(p1, p2, p3, p4, p5);
  return Caller< ReturnType, ReturnType(*)(X1, X2, X3, X4, X5), ListType >(f, l);
}


template < typename ReturnType, typename X1, typename X2, typename X3, typename X4, typename X5, typename X6, typename Param1, typename Param2, typename Param3, typename Param4, typename Param5, typename Param6 >

Caller< ReturnType, ReturnType(*)(X1, X2, X3, X4, X5, X6), typename Traits6< Param1, Param2, Param3, Param4, Param5, Param6 >::Type >
bind(ReturnType(*f)(X1, X2, X3, X4, X5, X6), Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6)
{
  typedef typename GetType< Param1 >::Type	P1;
  typedef typename GetType< Param2 >::Type	P2;
  typedef typename GetType< Param3 >::Type	P3;
  typedef typename GetType< Param4 >::Type	P4;
  typedef typename GetType< Param5 >::Type	P5;
  typedef typename GetType< Param6 >::Type	P6;
  typedef TypeList6< P1, P2, P3, P4, P5, P6 >	ListType;
  ListType l(p1, p2, p3, p4, p5, p6);
  return Caller< ReturnType, ReturnType(*)(X1, X2, X3, X4, X5, X6), ListType >(f, l);
}


template < typename ReturnType, typename Objet >

Caller< ReturnType, Objet, typename Traits0::Type >
bind(Objet& v)
{
  TypeList0 l;
  return Caller< ReturnType, Objet, Traits0::Type >(v, l); 
}

template < typename ReturnType, typename Param1, typename Objet>

Caller< ReturnType, Objet, typename Traits1< Param1 >::Type >
bind(Objet& v, Param1 p1)
{
  typedef typename GetType< Param1 >::Type	P1;
  typedef TypeList1< P1 >	ListType;
  ListType l(p1);
  return Caller< ReturnType, Objet, ListType >(v, l); 
}

template < typename ReturnType, typename Param1, typename Param2, typename Objet>

Caller< ReturnType, Objet, typename Traits2< Param1, Param2 >::Type >
bind(Objet& v, Param1 p1, Param2 p2)
{
  typedef typename GetType< Param1 >::Type	P1;
  typedef typename GetType< Param2 >::Type	P2;
  typedef TypeList2< P1, P2 >	ListType;
  ListType l(p1, p2);
  return Caller< ReturnType, Objet, ListType >(v, l); 
}

template < typename ReturnType, typename Param1, typename Param2, typename Param3, typename Objet>

Caller< ReturnType, Objet, typename Traits3< Param1, Param2, Param3 >::Type >
bind(Objet& v, Param1 p1, Param2 p2, Param3 p3)
{
  typedef typename GetType< Param1 >::Type	P1;
  typedef typename GetType< Param2 >::Type	P2;
  typedef typename GetType< Param3 >::Type	P3;
  typedef TypeList3< P1, P2, P3 >	ListType;
  ListType l(p1, p2, p3);
  return Caller< ReturnType, Objet, ListType >(v, l); 
}

template < typename ReturnType, typename Param1, typename Param2, typename Param3, typename Param4, typename Objet>

Caller< ReturnType, Objet, typename Traits4< Param1, Param2, Param3, Param4 >::Type >
bind(Objet& v, Param1 p1, Param2 p2, Param3 p3, Param4 p4)
{
  typedef typename GetType< Param1 >::Type	P1;
  typedef typename GetType< Param2 >::Type	P2;
  typedef typename GetType< Param3 >::Type	P3;
  typedef typename GetType< Param4 >::Type	P4;
  typedef TypeList4< P1, P2, P3, P4 >	ListType;
  ListType l(p1, p2, p3, p4);
  return Caller< ReturnType, Objet, ListType >(v, l); 
}


template < typename ReturnType, typename Param1, typename Param2, typename Param3, typename Param4, typename Param5, typename Objet>

Caller< ReturnType, Objet, typename Traits5< Param1, Param2, Param3, Param4, Param5 >::Type >
bind(Objet& v, Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5)
{
  typedef typename GetType< Param1 >::Type	P1;
  typedef typename GetType< Param2 >::Type	P2;
  typedef typename GetType< Param3 >::Type	P3;
  typedef typename GetType< Param4 >::Type	P4;
  typedef typename GetType< Param5 >::Type	P5;
  typedef TypeList5< P1, P2, P3, P4, P5 >	ListType;
  ListType l(p1, p2, p3, p4, p5);
  return Caller< ReturnType, Objet, ListType >(v, l); 
}

template < typename ReturnType, typename Param1, typename Param2, typename Param3, typename Param4, typename Param5, typename Param6, typename Objet>

Caller< ReturnType, Objet, typename Traits6< Param1, Param2, Param3, Param4, Param5, Param6 >::Type >
bind(Objet& v, Param1 p1, Param2 p2, Param3 p3, Param4 p4, Param5 p5, Param6 p6)
{
  typedef typename GetType< Param1 >::Type	P1;
  typedef typename GetType< Param2 >::Type	P2;
  typedef typename GetType< Param3 >::Type	P3;
  typedef typename GetType< Param4 >::Type	P4;
  typedef typename GetType< Param5 >::Type	P5;
  typedef typename GetType< Param6 >::Type	P6;
  typedef TypeList6< P1, P2, P3, P4, P5, P6 >	ListType;
  ListType l(p1, p2, p3, p4, p5, p6);
  return Caller< ReturnType, Objet, ListType >(v, l); 
}


#endif		/* !CALLER_HPP_*/
