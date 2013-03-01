#include "core/Server.hh"

int main()
{
  try
    {
      zia::core::Server s(4243, 5);
      s.run();
    }
  catch (zia::utils::Exception& e)
    {
      e.log();
    }
}
