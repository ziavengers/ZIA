#include "SocketReader.hh"
#include "core/Server.hh"
#include "utils/Logger.hpp"

SocketReader::SocketReader(const std::string& context, const std::string& input, const std::string& output) : zia::core::module::AModule(input, output, "SocketReader")
{
  this->connect(input, zia::utils::bind(&SocketReader::slot, *this), context);
}

void SocketReader::slot()
{
  zia::core::Server::SocketStream* stream;
  if ((stream = dynamic_cast< zia::core::Server::SocketStream* >(sender())))
    {
      try
	{
	  // LOG_INFO << "\033[32mRead:\033[0m " << stream->nextString();
	  stream->nextString();
	  contextEmit(context(), _sigOutput, stream);
	}
      catch (zia::utils::parsing::IProducterStream::Exception& e)
	{
	  LOG_INFO << "\033[32mDéconnexion\033[0m" << std::endl;
	  deleteLater();
	}
    }
}

SocketManager::SocketManager(const std::string& input, const std::string& output) : zia::core::module::AModule(input, output, "SocketManager")
{
  this->connect(input, zia::utils::bind(&SocketManager::slot, *this, ""));
}

void SocketManager::slot(const std::string& readSig)
{
  LOG_INFO << "\033[32mConnexion\033[0m" << std::endl;
  SocketReader* reader = new SocketReader(context(), readSig, _sigOutput);
  (void) reader;
}

extern "C"
{

  zia::core::module::IModule*	createModule(const std::string& s1, const std::string& s2, const std::map< std::string, std::string >&)
  {
    return new SocketManager(s1, s2);
  }

}

