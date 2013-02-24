#include "utils/Library.hh"

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
	  ::dlclose((*it).second);	
    }

    void	Library::add(const std::string& path, const std::string& name) throw(Exception)
    {

      void*	tmp = ::dlopen(path.c_str(), RTLD_LAZY);
      if (tmp == 0)
	throw Exception(std::string("Library:: Impossible de charger la librairie ") + path + std::string(::dlerror()));
      
      if (name.empty())
	_mlib[path] = tmp;
      else
	_mlib[name] = tmp;
    }

    void	Library::close(const std::string& name)
    {
      void	*tmp = _mlib[name];

      if (tmp)
	::dlclose(tmp);
      _mlib.erase(name);
    }    

  }
}
