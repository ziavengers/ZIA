/*
** TypeList.hpp for  in /home/nuts/local/ZIA/src/bind
** 
** Made by 
** Login   <nuts@epitech.net>
** 
** Started on  Thu Jan 24 21:53:56 2013 
** Last update Thu Jan 24 21:53:56 2013 
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


#endif		/* !TYPELIST_HPP_*/
