#include "SocketReader.hh"
#include "core/Server.hh"
#include "utils/Logger.hpp"

SocketReader::SocketReader(const std::string& input, const std::string& output) : zia::core::module::AModule(input, output, "SocketReader")
{
  this->connect(input, zia::utils::bind(&SocketReader::slot, *this));
}

void SocketReader::slot()
{
  zia::core::Server::SocketStream* stream;
  if ((stream = dynamic_cast< zia::core::Server::SocketStream* >(sender())))
    {
      try
	{
	  LOG_INFO << "\033[32mRead:\033[0m " << stream->nextString();
	  contextEmit(context(), _sigOutput, stream);
	}
      catch (zia::utils::parsing::IProducterStream::Exception& e)
	{
	  LOG_INFO << "\033[32mDéconnexion\033[0m" << std::endl;
	}
    }
}

extern "C"
{

  zia::core::module::IModule*	createModule(const std::string& s1, const std::string& s2, const std::map< std::string, std::string >&)
  {
    return new SocketReader(s1, s2);
  }

}

