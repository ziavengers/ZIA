#include <iostream>
#include <string>
#include <map>
#include <list>
#include "utils/bind.hpp"

class Object
{
public:
  virtual ~Object() {}
  void test(int a, int b)
  {
    std::cout << "Mais rien ne se passe " << a << ", " << b << std::endl;
  }
  void connect(const std::string& s, zia::utils::StockCallback slot)
  {
    _slots[s].push_back(slot);
  }
  template < typename T1, typename T2 >
  void emit(const std::string& s, T1 t1, T2 t2)
  {
    std::map< std::string, std::list< zia::utils::StockCallback > >::iterator itm;
    itm = _slots.find(s);
    if (itm != _slots.end())
      {
	std::list< zia::utils::StockCallback >::iterator it;
	for (it = itm->second.begin(); it != itm->second.end(); ++it)
	  {
	    typedef zia::utils::ParamCaller< typename zia::utils::Traits2< T1, T2 >::Type >* t_2int;
	    t_2int caller = dynamic_cast< t_2int >(it->caller());
	    if (caller)
	      {
	    	std::cout << "???" << std::endl;
	    	caller->set1(t1);
	    	caller->set2(t2);
	      }
	    (*it)();
	  }
      }
  }
private:
  static std::map< std::string, std::list< zia::utils::StockCallback > > _slots;
};

std::map< std::string, std::list< zia::utils::StockCallback > > Object::_slots;

class Object1 : public Object
{
public:
  void toto(int a, int b)
  {
    std::cout << "Object1::toto, a=" << a << ", b=" << b << std::endl;
  }
  void tata(double a, double b)
  {
    std::cout << "Object1::toto(double), a=" << a << ", b=" << b << std::endl;
  }
};

class Object2 : public Object
{
public:
  void tata(int a, int b)
  {
    std::cout << "Object2::tata, a=" << a << ", b=" << b << std::endl;
  }
};

int main()
{
  Object1 o;
  Object2 p;
  Object q;

  zia::utils::StockCallback s = zia::utils::bind(&Object::test, q, 0, 0);
  typedef zia::utils::ParamCaller< zia::utils::Traits2< int, int >::Type >* tt;
  tt s_ = dynamic_cast< tt >(s.caller());
  if (s_)
    {
      s_->set2(42);
    }
  s();

  o.connect("sig", zia::utils::bind(&Object1::toto, o, 0, 0));
  p.connect("sig", zia::utils::bind(&Object2::tata, p, 0, 0));
  q.connect("sig", zia::utils::bind(&Object::test, q, 42, 42));
  // o.emit("sig", 1, 2);
  q.emit("sig", 10, 2);

  o.connect("sig2", zia::utils::bind(&Object1::tata, o, 0., 0.));
  o.emit("sig2", 0.5, 0.7);
}
