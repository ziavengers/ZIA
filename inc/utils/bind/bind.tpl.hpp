template < typename ReturnType @X_typenames@ @Param_typenames@ >
Caller< ReturnType, ReturnType(*)(@X_params@), typename Traits@n@ @Param_templates@::Type >
bind(ReturnType(*f)(@X_params@) @Param_params@)
{
  @P_types@; // IGNORE_0
  typedef TypeList@n@ @P_templates@ ListType;
  ListType l@Param_params_simple@;
  return Caller< ReturnType, ReturnType(*)(@X_params@), ListType >(f, l);
}
    
template < typename ReturnType@Param_typenames@, typename Object >
Caller< ReturnType, Object, typename Traits@n@ @Param_templates@::Type >
bind(Object& o @Param_params@)
{
  @P_types@; // IGNORE_0
  typedef TypeList@n@ @P_templates@ ListType;
  ListType l@Param_params_simple@;
  return Caller< ReturnType, Object, ListType >(o, l);
}

// Param1 == Object // IGNORE_0
template < typename ReturnType @Param_typenames@ @X_typenames_next@ > // IGNORE_0
Caller< ReturnType, ReturnType (Param1::*)(@X_params_next@), typename TraitsMember@n@ @Param_templates@::Type > // IGNORE_0
bind(ReturnType (Param1::*func)(@X_params_next@) @Param_params@) // IGNORE_0
{ // IGNORE_0
  @P_types@; // IGNORE_0
  typedef TypeListMember@n@ @P_templates@ ListType; // IGNORE_0
  ListType l@Param_params_simple@; // IGNORE_0
  return Caller< ReturnType, ReturnType (Param1::*)(@X_params_next@), ListType >(func, l); // IGNORE_0
} // IGNORE_0
