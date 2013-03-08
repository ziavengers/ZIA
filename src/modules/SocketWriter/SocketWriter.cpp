#include "SocketWriter.hh"
#include "utils/Logger.hpp"

SocketWriter::SocketWriter(const std::string& input, const std::string& output) : zia::core::module::AModule(input, output, "SocketWriter")
{
  this->connect(input, zia::utils::bind(&SocketWriter::slot, *this, (zia::core::Server::SocketStream*) 0));
}

void SocketWriter::slot(zia::core::Server::SocketStream* stream)
{
  LOG_INFO << "context: " << context() << std::endl;
  if (stream)
    stream->write("merci\n");
}

extern "C"
{

  zia::core::module::IModule*	createModule(const std::string& s1, const std::string& s2, const std::map< std::string, std::string >&)
  {
    return new SocketWriter(s1, s2);
  }

}

