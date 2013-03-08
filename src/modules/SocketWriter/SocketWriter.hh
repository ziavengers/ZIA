#ifndef SOCKETWRITER_HH_
#define SOCKETWRITER_HH_

#include "core/module/Module.hh"
#include "utils/bind.hpp"
#include "core/Server.hh"

#include <iostream>

class	SocketWriter : public zia::core::module::AModule
{
public:
  SocketWriter(const std::string& input, const std::string& output);
  void	slot(zia::core::Server::SocketStream*);
};

#endif

