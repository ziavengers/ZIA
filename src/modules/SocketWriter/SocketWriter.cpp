#include "SocketWriter.hh"
#include "utils/Logger.hpp"
#include "http/Response.hh"

SocketWriter::SocketWriter(const std::string& input, const std::string& output) : zia::core::module::AModule(input, output, "SocketWriter")
{
  this->connect(input, zia::utils::bind(&SocketWriter::slot, *this, (zia::core::Server::SocketStream*) 0));
}

void SocketWriter::slot(zia::core::Server::SocketStream* stream)
{
  if (stream)
    {
      zia::http::Response resp("200", "OK", "HTTP");
      resp.header["Content-Size"] = "3";
      resp.header["Content-Type"] = "text/html";
      resp.data() = "ZIA";
      resp.write(std::cout);
      std::cout << std::endl;
      resp.write(*stream);
    }
}

extern "C"
{

  zia::core::module::IModule*	createModule(const std::string& s1, const std::string& s2, const std::map< std::string, std::string >&)
  {
    return new SocketWriter(s1, s2);
  }

}

