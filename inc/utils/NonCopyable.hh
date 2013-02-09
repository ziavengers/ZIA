/*
** NonCopyable.hh for  in /home/nuts/local/ZIA/src/utils
** 
** Made by 
** Login   <nuts@epitech.net>
** 
** Started on  Tue Feb 05 17:15:52 2013 
// Last update Fri Feb  8 15:13:47 2013 Rivot Corentin
*/

#ifndef		NONCOPYABLE_HH_
#define	NONCOPYABLE_HH_

namespace zia
{
    namespace utils
    {
	class NonCopyable
	{
	    public:
		~NonCopyable() { }

	    protected:
		NonCopyable() { }

	    private:
		NonCopyable(const NonCopyable&);
		NonCopyable& operator=(const NonCopyable&);
	};
    }
}


#endif		/* !NONCOPYABLE_HH_*/
