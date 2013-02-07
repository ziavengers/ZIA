template < @typenames@ > // IGNORE_0
struct Traits@n@
{
  @type_params@; // IGNORE_0
  typedef TypeList@n@ @templates_type_params@ Type;
};

template < @typenames@ > // IGNORE_0
struct TraitsMember@n@ // IGNORE_0
{ // IGNORE_0
  @type_params@; // IGNORE_0
  typedef TypeListMember@n@ @templates_type_params@ Type; // IGNORE_0
}; // IGNORE_0
