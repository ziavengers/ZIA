#ifndef UTILS_REGISTER_HPP_
#define UTILS_REGISTER_HPP_

#include <list>

#define TYPENAME(c)				\
  static const char* typeName()				\
  {							\
    return #c;						\
  }

namespace zia
{
  namespace utils
  {

    class TypeNames
    {
      template < int >
      struct DuckType
      {
	typedef char Type;
      };
      template < typename T >
      static const char* getOtherTypeName(typename DuckType< sizeof(&T::typeName) >::Type)
      {
      	return T::typeName();
      }
      template < typename >
      static const char* getOtherTypeName(...)
      {
      	return "???";
      }

      class IRegistered
      {
      public:
	virtual ~IRegistered() {}
	virtual const char* type() const = 0;
      };

      template < typename T >
      class Registered : public IRegistered
      {
	const char* _name;
      public:
	Registered(const char* name) : _name(name)
	{}
	const char* type() const
	{
	  return _name;
	}
      };

      class RegisteredList : public std::list< IRegistered* >
      {
      public:
	~RegisteredList()
	{
	  while (size())
	    {
	      delete front();
	      pop_front();
	    }
	}
      };
      static RegisteredList _types;

    public:
      template < typename T >
      static void register_(const char* name)
      {
	_types.push_back(new Registered< T >(name));
      }
      template < typename T >
      static const char* get()
      {
	std::list< IRegistered* >::iterator it;
	for (it = _types.begin(); it != _types.end(); ++it)
	  if (dynamic_cast< Registered< T >* >(*it))
	    return (*it)->type();
	return getOtherTypeName< T >(0);
      }
    };

  }
}

#include "utils/Singleton.hpp"

#define registerType(T) zia::utils::TypeNames::register_< T >(#T)
#define getTypeName(T) zia::utils::TypeNames::get< T >()

#endif
