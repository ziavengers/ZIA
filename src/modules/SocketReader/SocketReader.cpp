#include "SocketReader.hh"
#include "core/Server.hh"
#include "utils/Logger.hpp"
#include "utils/parsing/StringStream.hh"
#include "http/RequestParser.hh"

SocketReader::SocketReader(const std::string& context, const std::string& input, const std::string& output) : zia::core::module::AModule(input, output, "SocketReader"), _data()
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
	  // stream->nextString();
	  _data += stream->nextString();
	  // if (_data.find("\r\n\r\n") != std::string::npos)
	  if (_data.find("\n\n") != std::string::npos ||
	      _data.find("\r\r") != std::string::npos ||
	      _data.find("\r\n\r\n") != std::string::npos)
	    {
	      zia::utils::parsing::StringStream ss(_data);
	      LOG_INFO << "Parsing" << std::endl;
	      try
	      	{
		  zia::http::Request request = zia::http::RequestParser(ss).readHttp();
		  request.write(std::cout);
		  LOG_INFO << "End parsing" << std::endl;
	      	}
	      catch (zia::http::RequestParser::Exception& e)
	      	{
		  e.log();
		}
	      _data = "";
	      contextEmit(context(), _sigOutput, stream);
	    }
	  // contextEmit(context(), _sigOutput, stream);
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

