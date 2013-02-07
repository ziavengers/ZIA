template <typename R>
class RStockCallback
{
public:
  class Herited
  {
  public:
    virtual R operator()() = 0;
    virtual ~Herited() { }
  };
  template < class I >
  class Subterfuge : public Herited
  {
  public:
    Subterfuge(I& obj) : _func(obj) { }
    R	operator()()
    {
      return _func.operator()();
    }
  private:
    I	_func;
  };
  template < typename I >
  RStockCallback(I t)
  {
    _sub = new Subterfuge< I >(t);
  }
  RStockCallback(const RStockCallback<R>& s)
  {
    _sub = s._sub;
  }
  RStockCallback&	operator=(const RStockCallback<R>& s)
  {
    this->_sub = s._sub;
    return *this;
  }
  R	operator()()
  {
    return _sub->operator()();
  }
private:
  Herited	*_sub;
};

class StockCallback
{
public:
  class Herited
  {
  public:
    virtual void operator()() = 0;
    virtual ~Herited() { }
  };
  template < class I >
  class Subterfuge : public Herited
  {
  public:
    Subterfuge(I& obj) : _func(obj) { }
    void	operator()()
    {
      _func.operator()();
    }
  private:
    I	_func;
  };
  template < typename I >
  StockCallback(I t)
  {
    _sub = new Subterfuge< I >(t);
  }
  StockCallback(const StockCallback& s)
  {
    _sub = s._sub;
  }
  StockCallback&	operator=(const StockCallback& s)
  {
    this->_sub = s._sub;
    return *this;
  }
  void	operator()()
  {
    _sub->operator()();
  }
private:
  Herited	*_sub;
};
