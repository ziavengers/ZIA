template < @typenames@ > // IGNORE_0
struct TypeList@n@ : private Storage@n@ @templates@
{
  typedef Storage@n@ @templates@ BaseClass;
  TypeList@n@(@params@) : BaseClass(@params_names@) {}
  template < typename T >
    T& operator[](Value< T >& v)
  {
    return v.get();
  }
  template < typename ReturnType, typename Caller, typename List >
    ReturnType operator()(TypeTraits<ReturnType>, Caller& caller, List&
			  list // IGNORE_0
			  )
  {
    return caller(@list_params@);
  }
  @setters@
};
