template < typename ReturnType @X_typenames@ @Param_typenames@ >
Caller< ReturnType, ReturnType(*)(@X_params@), typename Traits@n@ @Param_templates@::Type >
bind(ReturnType(*f)(@X_params@) @Param_params@)
{
  @P_types@; // IGNORE_0
  typedef TypeList@n@ @P_templates@ ListType;
  ListType l@Param_params_simple@;
  std::string typeNames = @get_Param_type_names@;
  return Caller< ReturnType, ReturnType(*)(@X_params@), ListType >(f, l, typeNames);
}
    
template < typename ReturnType@Param_typenames@, typename Object >
Caller< ReturnType, Object, typename Traits@n@ @Param_templates@::Type >
bind(Object& o @Param_params@)
{
  @P_types@; // IGNORE_0
  typedef TypeList@n@ @P_templates@ ListType;
  ListType l@Param_params_simple@;
  std::string typeNames = @get_Param_type_names@;
  return Caller< ReturnType, Object, ListType >(o, l, typeNames);
}

template < typename ReturnType, typename Object @Param_typenames@ @X_typenames@ >
Caller< ReturnType, StockMethod@n@< Object, ReturnType @X_params_@ >, typename Traits@n@ @Param_templates@::Type >
bind(ReturnType (Object::*method)(@X_params@), Object& o @Param_params@)
{
  @P_types@; // IGNORE_0
  typedef TypeList@n@ @P_templates@ ListType;
  ListType l@Param_params_simple@;
  typedef StockMethod@n@< Object, ReturnType @X_params_@ > Parent;
  std::string typeNames = @get_Param_type_names@;
  return Caller< ReturnType, Parent, ListType >(Parent(o, method), l, typeNames);
}
