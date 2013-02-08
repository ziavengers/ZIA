//
// Singleton.hpp for hh in /home/nuts/local/rtype/serveur
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Wed Dec 19 09:25:50 2012 Rivot Corentin
// Last update Wed Feb  6 20:34:08 2013 Rivot Corentin
//

#ifndef SINGLETON_HPP_
#define SINGLETON_HPP_

#include "../thread/ScopedLock.hh"

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
	thread::Locker lock(&_mutex);
	if (!_instance)
	  _instance = new T;
	return _instance;
      }

      static void	kill()
      {
	thread::Locker lock(&_mutex);
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
