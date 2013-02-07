template <@typenames@> // IGNORE_0
struct TypeList@n@ : private Storage@n@ @templates@
{
  typedef Storage@n@ @templates@ BaseClass;
  TypeList@n@(@params@) : BaseClass(@params_names@) {}
  template <typename T>
    T& operator[](Value<T>& v)
  {
    return v.get();
  }
  template <typename ReturnType, typename Caller, typename List>
    ReturnType operator()(TypeTraits<ReturnType>, Caller& caller, List& list)
  {
    return caller(@list_params@);
  }
};

template <@typenames@> // IGNORE_0
struct TypeListMember@n@ : private Storage@n@ @templates@ // IGNORE_0
{ // IGNORE_0
  typedef Storage@n@ @templates@ BaseClass; // IGNORE_0
  TypeListMember@n@(@params@) : BaseClass(@params_names@) {} // IGNORE_0
  template <typename T> // IGNORE_0
    T& operator[](Value<T>& v) // IGNORE_0
  { // IGNORE_0
    return v.get(); // IGNORE_0
  } // IGNORE_0
  template <typename ReturnType, typename Caller, typename List> // IGNORE_0
    ReturnType operator()(TypeTraits<ReturnType>, Caller& caller, List& list) // IGNORE_0
  { // IGNORE_0
    return (list[BaseClass::_t1].*caller)(@list_params_next@); // IGNORE_0
  } // IGNORE_0
}; // IGNORE_0
