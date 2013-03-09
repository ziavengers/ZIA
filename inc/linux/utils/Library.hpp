#ifndef UTILS_LIBRARY_HPP_
#define UTILS_LIBRARY_HPP_

#include <map>
#include <string>

#include <dlfcn.h>

#include "utils/Exception.hpp"
#include "utils/NonCopyable.hh"

namespace zia
{
  namespace utils
  {

    class Library : public NonCopyable
    {
    public:

      CLASS_EXCEPTION("zia::utils::Library: ");

    public:

      explicit Library();
      ~Library();

      void	add(const std::string&, const std::string& = "") throw(Exception);
      void	close(const std::string&);

      template < typename T >
      T	getFunction(const std::string& s, const std::string& funcName) throw(Exception)
      {
	void	*tmp = _mlib[s];
	if (tmp == 0)
	  throw Exception("get : Can't load function " + funcName + " from " + s);
	
	T	fptr = reinterpret_cast< T >(::dlsym(tmp, funcName.c_str()));
	if (!fptr)
	  throw Exception("get : Can't load function " + funcName + " from " + s);
	return fptr;
      }      

    private:
      std::map< std::string, void* >	_mlib;
    };


  }
}



#endif
