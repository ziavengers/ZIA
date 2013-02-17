#include <dlfcn.h>
#include <iostream>
#include "utils/Object.hpp"

typedef zia::utils::Object* (*t_ctor)();

int main()
{
  zia::utils::Object o;
  zia::utils::Object* myo;

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
  o.emit("mysig", 4, 5);
  delete myo;

  dlclose(handle);
}
