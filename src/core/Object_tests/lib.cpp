#include <iostream>

#include "core/Object.hpp"

class MyObject : public zia::utils::Object
{
public:
  MyObject()
  {
    std::cout << "ctor" << std::endl;
    connect("mysig", zia::utils::bind(&MyObject::add, *this, 0, 0));
  }
  ~MyObject()
  {
    std::cout << "dtor" << std::endl;
  }
  void add(int a, int b)
  {
    std::cout << "Addition de " << a << " et " << b << std::endl;
  }
};

extern "C"
{
  zia::utils::Object* createObject()
  {
    return new MyObject;
  }
}
