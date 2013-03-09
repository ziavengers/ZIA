#include "utils/Library.hpp"

namespace zia
{
  namespace utils
  {

    Library::Library()
    {
      // ...
    }

    Library::~Library()
    {
      std::map< std::string, void * >::iterator	it;

      for (it = _mlib.begin(); it != _mlib.end(); ++it)
	if ((*it).second)
	  ::FreeLibrary((*it).second);	
    }

    void	Library::add(const std::string& path, const std::string& name) throw(Exception)
    {

      void*	tmp = ::LoadLibrary(TEXT(path.c_str()));
      if (tmp == 0)
	throw Exception(std::string("Library:: Impossible de charger la librairie ") + path + std::string(::dlerror()));
      
      if (name.empty())
	_mlib[path] = tmp;
      else
	_mlib[name] = tmp;
    }

    void	Library::close(const std::string& name)
    {
      HINSTANCE	tmp = _mlib[name];

      if (tmp)
	::FreeLibrary(tmp);
      _mlib.erase(name);
    }    


  }
}
