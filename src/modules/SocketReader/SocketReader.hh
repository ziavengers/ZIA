#ifndef SOCKETREADER_HH_
#define SOCKETREADER_HH_

#include "core/module/Module.hh"
#include "utils/bind.hpp"

#include <iostream>

class	SocketReader : public zia::core::module::AModule
{
public:
  SocketReader(const std::string& input, const std::string& output);
  void	slot();
};

#endif

