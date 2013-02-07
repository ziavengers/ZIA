template <@typenames@> // IGNORE_0
struct Storage@n@
  : public Storage@n_prec@ @templates_prec@ // IGNORE_0
{
  Storage@n@ (@params@)
    : Storage@n_prec@ @templates_prec@(@params_prec@), _t@n@(t@n@) // IGNORE_0
    {}
  T@n@ _t@n@; // IGNORE_0
};
