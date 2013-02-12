#include <iostream>
#include "core/Object.hpp"

class	Toto : public zia::core::Object
{
public:
  Toto() {
    this->connect("sendData", &Toto::iop, this);
    this->connect("sendInt", &Toto::io, this, 42);
  }

  int	iop()
  {
    std::cout << "Hello" << std::endl;
  }

  void	io(int o)
  {
    std::cout << "Hello int recut => " << o << std::endl;
  }
};

int	main()
{
  Toto t;
  
  t.emit("sendData");
  t.emit("sendInt");
  return 0;
}
