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
	    stream->write("merci\n");
	  }
	catch (IProducterStream::Exception& e)
	  {
	    std::cerr << "\033[32m" << "Déconnexion" << "\033[0m" << std::endl;
	  }
      }
  }
};

#include "core/Zia.hh"

int main()
{
  zia::core::Zia zia(4343, 5, 5);
  Toto t;
  t.connect("SocketStream::readable", zia::utils::bind(&Toto::slot, t));
  zia.run();
}
