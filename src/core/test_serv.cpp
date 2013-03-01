#include "core/Server.hh"

#include <iostream>

// class Toto : public zia::core::Object
// {
// public:
//   void slot(zia::network::ISocket* c)
//   {
//     char buff[101];
//     int len = c->read(buff, 100);
//     if (len > 0)
//       {
// 	buff[len] = 0;
// 	std::cout << buff;
//       }
//     else
//       emit("socket_close", c);
//   }
// };

#include "core/ThreadPool.hh"
#include "utils/Singleton.hpp"

int main()
{
  try
    {
      zia::utils::Singleton< zia::core::ThreadPool >::instance(new zia::core::ThreadPool(5));
      zia::utils::Singleton< zia::core::ThreadPool >::instance()->start();

      // Toto t;
      // t.connect("socket_readable", zia::utils::bind(&Toto::slot, t, static_cast< zia::network::ISocket* >(0)));
      zia::core::Server s(4243, 5);
      s.run();
    }
  catch (zia::utils::Exception& e)
    {
      e.log();
    }
}
