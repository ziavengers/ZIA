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

#endif		/* !CALLER_HPP_*/
