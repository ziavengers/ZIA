template < @typenames@ > // IGNORE_0
void emit(const std::string& name @params@)
{
  std::map< std::string, std::map< Object*, std::list< s_slot > > >::iterator itm;
  std::map< Object*, std::list< s_slot > >::iterator ito;
  std::list< s_slot >::iterator it;

  itm = _slots.find(name);
  if (itm != _slots.end())
    for (ito = itm->second.begin(); ito != itm->second.end(); ++ito)
      for (it = ito->second.begin(); it != ito->second.end(); ++it)
	{
	  typedef zia::utils::ParamCaller< typename zia::utils::Traits@n@@templates@::Type > t_caller;
	  t_caller* caller = dynamic_cast< t_caller* >(it->c.caller());
	  if (caller)
	    {
	      @setparams@
	      it->c();
	    }
	}
}
