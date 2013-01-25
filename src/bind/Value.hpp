/*
** Value.hpp for  in /home/nuts/local/ZIA/src/bind
** 
** Made by 
** Login   <nuts@epitech.net>
** 
** Started on  Thu Jan 24 20:31:29 2013 
** Last update Thu Jan 24 20:31:29 2013 
*/

#ifndef		VALUE_HPP_
# define	VALUE_HPP_

template < typename T >

class Value
{
    public:
	Value(T& t) : _t(t) { }

	T& get() {
	    return _t;
	}
	const T& get() const {
	    return _t;
	}

    private:
	T	_t;
};

template < typename T >

class GetType
{
    public:
	GetType( const T& t) { }

	typedef Value< T >	Type;
};

#endif		/* !VALUE_HPP_*/
