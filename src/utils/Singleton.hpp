//
// Singleton.hpp for hh in /home/nuts/local/rtype/serveur
// 
// Made by Rivot Corentin (nuts)
// Login   <corentin.rivot@gmail.com>
// 
// Started on  Wed Dec 19 09:25:50 2012 Rivot Corentin
// Last update Wed Dec 19 09:30:35 2012 Rivot Corentin
//

#ifndef SINGLETON_HPP_
#define SINGLETON_HPP_

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
			if (!_instance)
			    _instance = new T;
			return _instance;
		    }

		    static void	kill()
		    {
			if (_instance)
			    delete _instance;
		    }

		protected:
		    Singleton()
		    {
			m_instance = 0;
		    }

		    ~Singleton() { }

		private:
		    Singleton(const Singleton&);
		    ~Singleton(const Singleton&);

		    static T*	_instance;
	    };

	template < typename T >

	    T*	Singleton< T >::_instance = 0;

    }
}

#endif
