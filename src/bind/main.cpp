/*
** main.cpp for  in /home/nuts/local/ZIA/src/bind
** 
** Made by 
** Login   <nuts@epitech.net>
** 
** Started on  Thu Jan 24 22:56:49 2013 
** Last update Thu Jan 24 22:56:49 2013 
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

int	main()
{
    std::string ty("JE SUIS LE PARAMETRE");
    Caller<void, void(*)(), Traits0::Type >	func1 = bind(&toto);
    Caller< int, int(*)(std::string), Traits1< std::string >::Type >	func2 = bind(&withParam, ty);
    func1();
    func2();
}

