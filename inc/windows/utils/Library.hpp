#ifndef UTILS_LIBRARY_HH_
#define UTILS_LIBRARY_HH_

#include <map>
#include <string>

#include <windows.h>

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
	HINSTANCE tmp = _mlib[s];
	if (tmp == 0)
	  throw Exception(std::string("Library::get : Impossible de charger la fonction :") + funcName + std::string(" depuis ") + s);
	
	T	fptr = reinterpret_cast< T >(::GetProcAddress(tmp, funcName.c_str()));
	if (!fptr)
	  throw Exception(std::string("Library::get : Impossible de charger la fonction :") + funcName + std::string(" depuis ") + s);
	return fptr;
      }      

    private:
      std::map< std::string, HINSTANCE >	_mlib;


    };

  }
}


#endif
