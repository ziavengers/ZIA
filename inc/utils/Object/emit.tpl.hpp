template < @typenames@ > // IGNORE_0
void emit(const std::string& name @params@)
{
  std::map< std::string, std::list< StockCallback > >::iterator itm;
  itm = _slots.find(name);
  if (itm != _slots.end())
    {
      std::list< zia::utils::StockCallback >::iterator it;
      for (it = itm->second.begin(); it != itm->second.end(); ++it)
	{
	  typedef zia::utils::ParamCaller< typename zia::utils::Traits@n@@templates@::Type > t_caller;
	  t_caller* caller = dynamic_cast< t_caller* >(it->caller());
	  if (caller)
	    {
	      @setparams@
	      (*it)();
	    }
	}
    }
}
