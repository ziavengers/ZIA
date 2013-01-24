/*
** TypeTraits.hpp for  in /home/nuts/local/ZIA/src/bind
** 
** Made by 
** Login   <nuts@epitech.net>
** 
** Started on  Thu Jan 24 21:32:36 2013 
** Last update Thu Jan 24 21:32:36 2013 
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
/*
 *	Edit this file to support more parameters
 */

#endif		/* !TYPETRAITS_HPP_*/
