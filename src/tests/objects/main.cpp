#include <dlfcn.h>
#include <iostream>
#include "core/Object.hpp"
#include "core/ThreadPool.hh"
#include "utils/Singleton.hpp"

typedef zia::core::Object* (*t_ctor)();

class AAA : public zia::core::Object
{
public:
  void aaa()
  {
    sender()->disconnect("mysig");
    // sender()
    // sender()->deleteLater();
    emit("mysig", 1, 1);
    sender()->deleteLater();
  }
};

int main()
{
  zia::utils::Singleton< zia::core::ThreadPool >::instance(new zia::core::ThreadPool(5));
  zia::utils::Singleton< zia::core::ThreadPool >::instance()->start();
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
  (void) myo;
  o.connect("huhu", zia::utils::bind(&AAA::aaa, o));
  o.emit("mysig", 1, 2);
  try
    {
      o.emit("mysig", 1);
    }
  catch (std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }
  // myo->disconnect("mysig");
  // o.emit("mysig", 4, 5);
  // delete myo;
  // myo->deleteLater();

  // zia::utils::Singleton< zia::core::ThreadPool >::instance()->wait();
  while (1)
    ;

  dlclose(handle);
}
