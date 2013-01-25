/*
** main.cpp for  in /home/nuts/local/ZIA/src/bind
** 
** Made by 
** Login   <nuts@epitech.net>
** 
** Started on  Thu Jan 24 22:56:49 2013 
// Last update Fri Jan 25 12:30:12 2013 Rivot Corentin
*/

#include <string>
#include <iostream>
#include "Caller.hpp"

void	toto()
{
    std::cout << "Coucou, je suis SANS parametre" << std::endl;
}

int	withParam(std::string st)
{
    std::cout << "Coucou, je suis AVEC 1 parametre std::string " << st << std::endl;
    return 42;
}

class Toto
{
    public:
	Toto() { }

	void operator()()
	{
	    std::cout << "Coucou, Je suis un objet callable SANS parametre" << std::endl;
	}
};

int	add(int i, int j, int k, int p, int o, int u)
{
  return i + j + k + p + o + u;
}

int	main()
{
    std::string ty("JE SUIS LE PARAMETRE");
    Caller<void, void(*)(), Traits0::Type >	func1 = bind(&toto);
    Caller< int, int(*)(std::string), Traits1< std::string >::Type >	func2 = bind(&withParam, ty);
    func1();
    func2();
    Toto t;
    bind< void >(t)();
    std::cout << bind(&add, 2, 3, 4, 8, 16, 32)() << std::endl;
}

