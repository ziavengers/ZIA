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
  try
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
	    {
	      std::cout << it3->instr() << ":";
	      std::list< std::string >::const_iterator it4;
	      for (it4 = it3->args().begin(); it4 != it3->args().end(); ++it4)
		std::cout << ", " << *it4;
	      std::map< std::string, std::string >::const_iterator it5;
	      for (it5 = it3->kwargs().begin(); it5 != it3->kwargs().end(); ++it5)
		std::cout << ", " << it5->first << "=" << it5->second;
	      std::cout << std::endl;
	    }
	  std::cout << std::endl;
	}
      std::cout << "END" << std::endl;
    }
  catch (zia::utils::Exception& e)
    {
      e.log();
    }

  zia::core::Zia zia(4343, 5, 5);
  Toto t;
  t.connect("SocketStream::readable", zia::utils::bind(&Toto::slot, t));
  zia.run();
}
