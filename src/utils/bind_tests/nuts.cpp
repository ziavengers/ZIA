#include <string>
#include <iostream>
#include "utils/bind.hpp"
#include "utils/StockCallback.hpp"

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
	    return 0;
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

  int	add()
  {
    std::cout << "Coucou, je suis une fonction membre de Toto" << std::endl;
    return 0;
  }
  int	add(int a, int b)
  {
    std::cout << "Coucou, je suis une autre fonction membre de Toto" << std::endl;
    return (a + b);
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
    zia::utils::Caller<void, void(*)(), zia::utils::Traits0::Type >	func1 = zia::utils::bind(&toto);
    
    zia::utils::StockCallback s(zia::utils::bind(&toto));
    s();

    zia::utils::Caller< int, int(*)(std::string), zia::utils::Traits1< std::string >::Type >	func2 = zia::utils::bind(&withParam, ty);
    zia::utils::StockCallback s2(func2);
    func2();
    
    func1();
    func2();
    Toto t;
    zia::utils::bind< int >(t)();
    std::cout << zia::utils::bind(&add, 2, 3)() << std::endl;
    std::cout << zia::utils::bind< int >(t, 2, 3, 4, 9, 18, 36)() << std::endl;
    std::cout << zia::utils::bind< int >(t, 2, 3)() << std::endl;
    std::cout << zia::utils::bind(&Toto::add, t)() << std::endl;
    std::cout << zia::utils::bind(&Toto::add, t, 42, 21)() << std::endl;

    zia::utils::RStockCallback<int> s3(zia::utils::bind(add, 1, 2));
    std::cout << s3() << std::endl;

    zia::utils::StockCallback s4(zia::utils::bind(add, 1, 2));
    s4();
}

