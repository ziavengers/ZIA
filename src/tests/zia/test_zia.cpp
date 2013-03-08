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
	catch (zia::utils::parsing::IProducterStream::Exception& e)
	  {
	    std::cerr << "\033[32m" << "Déconnexion" << "\033[0m" << std::endl;
	  }
      }
  }
};

#include "core/Zia.hh"
#include "utils/parsing/FileStream.hh"
#include "utils/ini/ReadIni.hh"
#include "core/Settings.hpp"
#include "utils/uuid.hh"

int main()
{
  zia::core::Zia zia("test.ini");
  // zia::utils::uuid::uuid4 u;
  // LOG_DEBUG << u.str() << std::endl;
  Toto t;
  t.connect("SocketStream::readable", zia::utils::bind(&Toto::slot, t));
  zia.run();
}
