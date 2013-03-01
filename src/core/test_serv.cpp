#include "core/Server.hh"

#include <iostream>

class Toto : public zia::core::Object
{
public:
  void slot()
  {
    zia::core::Server::SocketStream* stream;
    if ((stream = dynamic_cast< zia::core::Server::SocketStream* >(sender())))
      {
	try
	  {
	    std::cout << stream->nextString();
	  }
	catch (IProducterStream::Exception& e)
	  {
	    std::cerr << "\033[32m" << "Déconnexion" << "\033[0m" << std::endl;
	  }
      }
  }
};

#include "core/ThreadPool.hh"
#include "utils/Singleton.hpp"

int main()
{
  try
    {
      zia::utils::Singleton< zia::core::ThreadPool >::instance(new zia::core::ThreadPool(5));
      zia::utils::Singleton< zia::core::ThreadPool >::instance()->start();

      Toto t;
      t.connect("SocketStream::readable", zia::utils::bind(&Toto::slot, t));
      zia::core::Server s(4343, 5);
      s.run();
    }
  catch (zia::utils::Exception& e)
    {
      e.log();
    }
}
