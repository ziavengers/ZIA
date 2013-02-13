// JUST_ONCE

template < typename List >
class ParamCaller : public ICaller
{
public:
  ParamCaller(List list) : _list(list) {}
  // /!\ Ne passer que des primitifs ou des références/pointeurs, sinon copie
  @setters@
protected:
  List _list;
};
