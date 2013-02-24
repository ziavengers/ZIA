#include "core/Zia.hh"

namespace zia
{
  namespace core
  {

    Zia::Zia(int port, int serverQueueSize, int nbThreads) : _pool(nbThreads)
    {}

  }
}
