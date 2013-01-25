/*
** TypeTraits.hpp for  in /home/nuts/local/ZIA/src/bind
** 
** Made by 
** Login   <nuts@epitech.net>
** 
** Started on  Thu Jan 24 21:32:36 2013 
// Last update Fri Jan 25 15:03:13 2013 Rivot Corentin
*/

#ifndef		TYPETRAITS_HPP_
# define	TYPETRAITS_HPP_

#include "Value.hpp"

template < typename T >

struct TypeTraits
{
  typedef T	type;
};

struct TypeList0;

struct Traits0
{
  typedef TypeList0	Type;
};

template < typename T1 >
struct TypeList1;

template < typename T1 >
struct Traits1
{
  typedef typename GetType< T1 >::Type	Type_Parameter1;
  typedef TypeList1< Type_Parameter1 >	Type;
};

template < typename T1, typename T2 >
struct TypeList2;


template < typename T1, typename T2 >
struct Traits2
{
  typedef typename GetType< T1 >::Type	Type_Parameter1;
  typedef typename GetType< T2 >::Type	Type_Parameter2;
  typedef TypeList2< Type_Parameter1, Type_Parameter2 >	Type;
};


template < typename T1, typename T2, typename T3 >
struct TypeList3;


template < typename T1, typename T2, typename T3 >
struct Traits3
{
  typedef typename GetType< T1 >::Type	Type_Parameter1;
  typedef typename GetType< T2 >::Type	Type_Parameter2;
  typedef typename GetType< T3 >::Type	Type_Parameter3;
  typedef TypeList3< Type_Parameter1, Type_Parameter2, Type_Parameter3 >	Type;
};


template < typename T1, typename T2, typename T3, typename T4 >
struct TypeList4;


template < typename T1, typename T2, typename T3, typename T4 >
struct Traits4
{
  typedef typename GetType< T1 >::Type	Type_Parameter1;
  typedef typename GetType< T2 >::Type	Type_Parameter2;
  typedef typename GetType< T3 >::Type	Type_Parameter3;
  typedef typename GetType< T4 >::Type	Type_Parameter4;
  typedef TypeList4< Type_Parameter1, Type_Parameter2, Type_Parameter3, Type_Parameter4 >	Type;
};


template < typename T1, typename T2, typename T3, typename T4, typename T5>
struct TypeList5;


template < typename T1, typename T2, typename T3, typename T4, typename T5 >
struct Traits5
{
  typedef typename GetType< T1 >::Type	Type_Parameter1;
  typedef typename GetType< T2 >::Type	Type_Parameter2;
  typedef typename GetType< T3 >::Type	Type_Parameter3;
  typedef typename GetType< T4 >::Type	Type_Parameter4;
  typedef typename GetType< T5 >::Type	Type_Parameter5;
  typedef TypeList5< Type_Parameter1, Type_Parameter2, Type_Parameter3, Type_Parameter4, Type_Parameter5 >	Type;
};


template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
struct TypeList6;


template < typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
struct Traits6
{
  typedef typename GetType< T1 >::Type	Type_Parameter1;
  typedef typename GetType< T2 >::Type	Type_Parameter2;
  typedef typename GetType< T3 >::Type	Type_Parameter3;
  typedef typename GetType< T4 >::Type	Type_Parameter4;
  typedef typename GetType< T5 >::Type	Type_Parameter5;
  typedef typename GetType< T6 >::Type	Type_Parameter6;
  typedef TypeList6< Type_Parameter1, Type_Parameter2, Type_Parameter3, Type_Parameter4, Type_Parameter5, Type_Parameter6 >	Type;
};




/*
 *
 *	Edit this file to support more parameters
 */
///////////// 
/// MEMBER FPTR


template < typename T1 >
struct TypeListMember1;

template < typename T1 >
struct TraitsMember1
{
  typedef typename GetType< T1 >::Type	Type_Parameter1;
  typedef TypeListMember1< Type_Parameter1 >	Type;
};


#endif		/* !TYPETRAITS_HPP_*/
