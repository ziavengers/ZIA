/*
** TypeList.hpp for  in /home/nuts/local/ZIA/src/bind
** 
** Made by 
** Login   <nuts@epitech.net>
** 
** Started on  Thu Jan 24 21:53:56 2013 
// Last update Fri Jan 25 12:17:43 2013 Rivot Corentin
*/

#ifndef		TYPELIST_HPP_
# define	TYPELIST_HPP_

#include "TypeTraits.hpp"
#include "Storage.hpp"
#include "Value.hpp"

struct TypeList0 : private Storage0
{
  typedef Storage0	BaseClass;

  TypeList0() : BaseClass()
  {
    // useless
  }

  // Don't use this operator with TypeList level 0
  template < typename T >
	
  T&	operator[](Value< T >& n)
  {
  }

  template < typename ReturnType, typename Caller, typename List >

  ReturnType	operator()(TypeTraits< ReturnType > q, Caller& caller, List& l)
  {
    return caller();
  }
};

template < typename T1 >

struct TypeList1 : private Storage1< T1 >
{
  typedef Storage1< T1 >	BaseClass;

  TypeList1(T1 t1) : BaseClass(t1)
  {
    // useless
  }

  template < typename T >
	
  T&	operator[](Value< T >& n)
  {
    return n.get();
  }

  template < typename ReturnType, typename Caller, typename List >

  ReturnType	operator()(TypeTraits< ReturnType > q, Caller& caller, List& l)
  {
    return caller(l.operator[](BaseClass::_t1));
  }
};


template < typename T1, typename T2 >

struct TypeList2 : private Storage2< T1, T2 >
{
  typedef Storage2< T1, T2 >	BaseClass;

  TypeList2(T1 t1, T2 t2) : BaseClass(t1, t2)
  {
    // useless
  }

  template < typename T >
	
  T&	operator[](Value< T >& n)
  {
    return n.get();
  }

  template < typename ReturnType, typename Caller, typename List >

  ReturnType	operator()(TypeTraits< ReturnType > q, Caller& caller, List& l)
  {
    return caller(l[BaseClass::_t1],
		  l[BaseClass::_t2]);
  }
};

template < typename T1, typename T2, typename T3 >

struct TypeList3 : private Storage3< T1, T2, T3 >
{
  typedef Storage3< T1, T2, T3 >	BaseClass;

  TypeList3(T1 t1, T2 t2, T3 t3) : BaseClass(t1, t2, t3)
  {
    // useless
  }

  template < typename T >
	
  T&	operator[](Value< T >& n)
  {
    return n.get();
  }

  template < typename ReturnType, typename Caller, typename List >

  ReturnType	operator()(TypeTraits< ReturnType > q, Caller& caller, List& l)
  {
    return caller(l[BaseClass::_t1],
		  l[BaseClass::_t2],
		  l[BaseClass::_t3]
		  );
  }
};


template < typename T1, typename T2, typename T3, typename T4 >

struct TypeList4 : private Storage4< T1, T2, T3, T4>
{
  typedef Storage4< T1, T2, T3, T4 >	BaseClass;

  TypeList4(T1 t1, T2 t2, T3 t3, T4 t4) : BaseClass(t1, t2, t3, t4)
  {
    // useless
  }

  template < typename T >
	
  T&	operator[](Value< T >& n)
  {
    return n.get();
  }

  template < typename ReturnType, typename Caller, typename List >

  ReturnType	operator()(TypeTraits< ReturnType > q, Caller& caller, List& l)
  {
    return caller(l[BaseClass::_t1],
		  l[BaseClass::_t2],
		  l[BaseClass::_t3],
		  l[BaseClass::_t4]
		  );
  }
};


template < typename T1, typename T2, typename T3, typename T4, typename T5 >

struct TypeList5 : private Storage5< T1, T2, T3, T4, T5 >
{
  typedef Storage5< T1, T2, T3, T4, T5 >	BaseClass;

  TypeList5(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5) : BaseClass(t1, t2, t3, t4, t5)
  {
    // useless
  }

  template < typename T >
	
  T&	operator[](Value< T >& n)
  {
    return n.get();
  }

  template < typename ReturnType, typename Caller, typename List >

  ReturnType	operator()(TypeTraits< ReturnType > q, Caller& caller, List& l)
  {
    return caller(l[BaseClass::_t1],
		  l[BaseClass::_t2],
		  l[BaseClass::_t3],
		  l[BaseClass::_t4],
		  l[BaseClass::_t5]
		  );
  }
};


template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >

struct TypeList6 : private Storage6< T1, T2, T3, T4, T5, T5 >
{
  typedef Storage6< T1, T2, T3, T4, T5, T6 >	BaseClass;

  TypeList6(T1 t1, T2 t2, T3 t3, T4 t4, T5 t5, T6 t6) : BaseClass(t1, t2, t3, t4, t5, t6)
  {
    // useless
  }

  template < typename T >
	
  T&	operator[](Value< T >& n)
  {
    return n.get();
  }

  template < typename ReturnType, typename Caller, typename List >

  ReturnType	operator()(TypeTraits< ReturnType > q, Caller& caller, List& l)
  {
    return caller(l[BaseClass::_t1],
		  l[BaseClass::_t2],
		  l[BaseClass::_t3],
		  l[BaseClass::_t4],
		  l[BaseClass::_t5],
		  l[BaseClass::_t6]
		  );
  }
};


#endif		/* !TYPELIST_HPP_*/
