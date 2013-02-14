template < typename Object, typename ReturnType @typenames@ >
class StockMethod@n@
{
 public:
  StockMethod@n@ (Object& o, ReturnType (Object::*m)(@params_types@)) : _o(o), _m(m) {}
  ReturnType operator()(@params@)
  {
    return (_o.*_m)(@params_names@);
  }
 private:
  Object& _o;
  ReturnType (Object::*_m)(@params_types@);
};
