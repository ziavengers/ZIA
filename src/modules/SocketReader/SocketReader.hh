#ifndef SOCKETREADER_HH_
#define SOCKETREADER_HH_

#include "core/module/Module.hh"
#include "utils/bind.hpp"

#include <iostream>

class	SocketReader : public zia::core::module::AModule
{
public:
  SocketReader(const std::string& context, const std::string& input, const std::string& output);
  void	slot();
};

class	SocketManager : public zia::core::module::AModule
{
public:
  SocketManager(const std::string& input, const std::string& output);
  void	slot(const std::string&);
};

#endif

