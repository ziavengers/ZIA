// JUST_ONCE

template < typename List >
class ParamCaller : public ICaller
{
public:
  ParamCaller(List list, const std::string& paramTypeNames = "") : _list(list), _paramTypeNames(paramTypeNames) {}
  const std::string& paramTypeNames() const
  {
    return _paramTypeNames;
  }
  // /!\ Ne passer que des primitifs ou des références/pointeurs, sinon copie
  @setters@
protected:
  List _list;
  std::string _paramTypeNames;
};
