#include "bind.hpp"

int addition0()
{
  return 0;
}

int addition1(int a)
{
  return a;
}

int addition2(int a, int b)
{
  return (a + b);
}

int addition3(int a, int b, int c)
{
  return (a + b + c);
}

int addition4(int a, int b, int c, int d)
{
  return (a + b + c + d);
}

int addition5(int a, int b, int c, int d, int e)
{
  return (a + b + c + d + e);
}

int addition6(int a, int b, int c, int d, int e, int f)
{
  return (a + b + c + d + e + f);
}

#include <iostream>

int main()
{
  std::cout << bind(addition0)() << std::endl;
  std::cout << bind(addition1, 1)() << std::endl;
  std::cout << bind(addition2, 1, 2)() << std::endl;
  std::cout << bind(addition3, 1, 2, 3)() << std::endl;
  std::cout << bind(addition4, 1, 2, 3, 4)() << std::endl;
  std::cout << bind(addition5, 1, 2, 3, 4, 5)() << std::endl;
  std::cout << bind(addition6, 1, 2, 3, 4, 5, 6)() << std::endl;
}
