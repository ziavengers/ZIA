/*
** main.cpp for  in /home/nuts/local/ZIA/src/bind
** 
** Made by 
** Login   <nuts@epitech.net>
** 
** Started on  Thu Jan 24 22:56:49 2013 
// Last update Fri Jan 25 12:55:45 2013 Rivot Corentin
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

	int operator()()
	{
	    std::cout << "Coucou, Je suis un objet callable SANS parametre" << std::endl;
	}

  int operator()(int i)
  {
    return i;
  }

  int operator()(int i, int j)
  {
    return i + j;
  }

  int operator()(int i, int j, int k, int o, int y, int u)
  {
    return i + j + k + o + y + u;
  }
};

int	add(int i, int j, int k, int p, int o)
{
  return i + j + k + p + o;
}

int add(int i, int j)
{
  return i+j;
}

void test(std::string t, std::string i)
{
  std::cout <<t << std::endl;
  std::cout <<i << std::endl;
}

int	main()
{
    std::string ty("JE SUIS LE PARAMETRE");
    std::string tt("JE SUIS LE PARAMETRE2");
    Caller<void, void(*)(), Traits0::Type >	func1 = bind(&toto);
    Caller< int, int(*)(std::string), Traits1< std::string >::Type >	func2 = bind(&withParam, ty);
    func1();
    func2();
    Toto t;
    bind< int >(t)();
    std::cout << bind(&add, 2, 3)() << std::endl;
    std::cout << bind< int, int, int, int, int, int >(t, 2, 3, 4, 9, 18, 36)() << std::endl;
}

