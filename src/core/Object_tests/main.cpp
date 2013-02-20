#include <dlfcn.h>
#include <iostream>
#include "core/Object.hpp"

typedef zia::core::Object* (*t_ctor)();

class AAA : public zia::core::Object
{
public:
  void aaa()
  {
    std::cout << "aaa" << std::endl;
    emit("mysig", 1, 1);
  }
};

int main()
{
  AAA o;
  zia::core::Object* myo;

  void* handle = dlopen("./libtest.so", RTLD_LAZY);
  if (!handle)
    {
      std::cout << dlerror() << std::endl;
      return 0;
    }
  t_ctor ctor = (t_ctor) dlsym(handle, "createObject");
  if (!handle)
    {
      std::cout << dlerror() << std::endl;
      return 0;
    }

  myo = ctor();
  o.connect("huhu", zia::utils::bind(&AAA::aaa, o));
  o.emit("mysig", 1, 2);
  myo->disconnect("mysig");
  o.emit("mysig", 4, 5);
  delete myo;

  dlclose(handle);
}
