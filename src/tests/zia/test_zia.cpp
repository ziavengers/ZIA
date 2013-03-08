#include "core/Server.hh"
#include "core/Zia.hh"

int main()
{
  zia::core::Zia zia("test.ini");
  zia.run();
}
