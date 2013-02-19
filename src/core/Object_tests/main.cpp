#include <dlfcn.h>
#include <iostream>
#include "core/Object.hpp"

typedef zia::core::Object* (*t_ctor)();

int main()
{
  zia::core::Object o;
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
  o.emit("mysig", 1, 2);
  myo->disconnect("mysig");
  o.emit("mysig", 4, 5);
  delete myo;

  dlclose(handle);
}
