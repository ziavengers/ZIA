#include "thread/Locker.hh"

namespace zia
{
namespace thread
{

  Locker::Locker(IMutex* m)
  {
    _mutex = m;
    _mutex->lock();
  }

  Locker::~Locker()
  {
    _mutex->unlock();
  }

}
}
