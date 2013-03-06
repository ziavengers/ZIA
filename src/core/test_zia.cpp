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

int main()
{
  zia::utils::parsing::FileStream f("test.ini");
  zia::utils::ini::ReadIni ri(f);
  zia::utils::ini::Ini ini = ri.parse();
  std::map< std::string, zia::utils::ini::Ini::Section >::const_iterator it;
  for (it = ini.sections().begin(); it != ini.sections().end(); ++it)
    {
      std::cout << "[" << it->first << "]" << std::endl;
      std::map< std::string, std::string >::const_iterator it2;
      for (it2 = it->second.vars().begin(); it2 != it->second.vars().end(); ++it2)
	std::cout << it2->first << " = " << it2->second << std::endl;
      std::list< zia::utils::ini::Ini::Section::Instruction >::const_iterator it3;
      for (it3 = it->second.instructions().begin(); it3 != it->second.instructions().end(); ++it3)
	std::cout << it3->instr() << ":" << std::endl;
      std::cout << std::endl;
    }
  std::cout << "END" << std::endl;

  zia::core::Zia zia(4343, 5, 5);
  Toto t;
  t.connect("SocketStream::readable", zia::utils::bind(&Toto::slot, t));
  zia.run();
}
