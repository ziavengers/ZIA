/*
** main.cpp for  in /home/nuts/local/ZIA/src/bind
** 
** Made by 
** Login   <nuts@epitech.net>
** 
** Started on  Thu Jan 24 22:56:49 2013 
** Last update Thu Jan 24 22:56:49 2013 
*/

#include <iostream>
#include "Caller.hpp"

void	toto()
{
    std::cout << "Coucou, je suis SANS parametre" << std::endl;
}

int	main()
{
    Caller<void, void(*)(), Traits0::Type >	func1 = bind(&toto);
    func1();
}

