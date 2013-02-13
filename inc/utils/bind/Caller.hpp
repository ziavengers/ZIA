#ifndef CALLER_HPP_
#define CALLER_HPP_

// #include "ICaller.hpp"
#include "build/ParamCaller.hpp"

// template < typename List >
// class ParamCaller : public ICaller
// {
// public:
//   ParamCaller(List list) : _list(list) {}
//   // /!\ Ne passer que des primitifs ou des références/pointeurs, sinon copie
//   template < typename T >
//   void set1(T t)
//   {
//     _list.set1(Value< T >(t));
//   }
//   template < typename T >
//   void set2(T t)
//   {
//     _list.set2(Value< T >(t));
//   }
//   template < typename T >
//   void set3(T t)
//   {
//     _list.set3(Value< T >(t));
//   }
//   template < typename T >
//   void set4(T t)
//   {
//     _list.set4(Value< T >(t));
//   }
//   template < typename T >
//   void set5(T t)
//   {
//     _list.set5(Value< T >(t));
//   }
//   template < typename T >
//   void set6(T t)
//   {
//     _list.set6(Value< T >(t));
//   }
// protected:
//   List _list;
// };

template <typename ReturnType, typename Callable, typename List>
class Caller : public ParamCaller< List >
{
public:
  Caller(Callable callable, List list) : ParamCaller< List >(list), _callable(callable) {}
  ReturnType operator()()
  {
    return this->_list(TypeTraits<ReturnType>(), _callable, this->_list);
  }
protected:
  Callable _callable;
};

#endif
