#include "core/Server.hh"
#include "core/Zia.hh"

// #include "utils/uuid.hh"

int main()
{
  zia::core::Zia zia("test.ini");
  // zia::utils::uuid::uuid4 u;
  // LOG_DEBUG << u.str() << std::endl;
  zia.run();
}
