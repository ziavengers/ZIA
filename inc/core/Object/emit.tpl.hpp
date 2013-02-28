template < @typenames@ > // IGNORE_0
void emit(const std::string& name @params@)
{
  thread::Locker lock(_slotsMutex);
  std::map< std::string, std::map< Object*, std::list< s_slot > > >::iterator itm;
  std::map< Object*, std::list< s_slot > >::iterator ito;
  std::list< s_slot >::iterator it;

  itm = _slots.find(name);
  if (itm != _slots.end())
    for (ito = itm->second.begin(); ito != itm->second.end(); ++ito)
      for (it = ito->second.begin(); it != ito->second.end(); ++it)
	{
	  typedef utils::ParamCaller< typename utils::Traits@n@@templates@::Type > t_caller;
	  t_caller* caller = dynamic_cast< t_caller* >(it->c.caller());
	  if (caller)
	    {
	      @setparams@
	      zia::utils::Singleton< zia::core::ThreadPool >::instance()->push(this, ito->first, it->c);
	    }
	  else
	    {
	      std::string types = @get_type_names@;
	      throw Signal::Exception(std::string("Invalid slot for signal ") + name + std::string("(") + types + std::string(") not compatible with (") + it->c.caller()->paramTypeNames() + std::string(")"));
	    }
	}
}
