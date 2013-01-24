/*
** Caller.hpp for  in /home/nuts/local/ZIA/src/bind
** 
** Made by 
** Login   <nuts@epitech.net>
** 
** Started on  Thu Jan 24 21:43:28 2013 
** Last update Thu Jan 24 21:43:28 2013 
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
    //TypeList1< Param1 >	l(p1);
    return Caller< ReturnType, ReturnType(*)(X1), ListType >(f, l);
}

#endif		/* !CALLER_HPP_*/
