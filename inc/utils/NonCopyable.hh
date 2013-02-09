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
