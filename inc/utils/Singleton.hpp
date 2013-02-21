#ifndef SINGLETON_HPP_
#define SINGLETON_HPP_

#include "thread/Locker.hh"

namespace zia
{
  namespace utils
  {

    template < typename T >

    class Singleton
    {
    public:
      static T*	instance()
      {
	thread::Locker lock(_mutex);
	if (!_instance)
	  _instance = new T;
	return _instance;
      }
      static T*	instance(T* instance)
      {
	thread::Locker lock(_mutex);
	if (!_instance)
	  // _instance = new T;
	  _instance = instance;
	return _instance;
      }

      static void	kill()
      {
	thread::Locker lock(_mutex);
	if (_instance)
	  delete _instance;
	_instance = 0;
      }

    protected:
      Singleton()
      {
	_instance = 0;
      }

      ~Singleton() { _instance = 0; }

    private:
      Singleton(const Singleton&);
      Singleton& operator&(const Singleton&);

      static thread::Mutex	_mutex;
      static T*	_instance;
    };

    template < typename T >
    T*	Singleton< T >::_instance = 0;

    template < typename T >
    thread::Mutex	Singleton< T >::_mutex;

  }
}

#endif
