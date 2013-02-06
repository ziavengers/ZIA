/*
** Logger.hh for  in /home/nuts/local/ZIA/src/utils
** 
** Made by 
** Login   <nuts@epitech.net>
** 
** Started on  Tue Feb 05 18:07:01 2013 
// Last update Wed Feb  6 21:41:23 2013 Rivot Corentin
*/

#ifndef		LOGGER_HH_
# define	LOGGER_HH_

#include <string>
#include <fstream>

#include "Singleton.hpp"
#include "NonCopyable.hh"

/*

  Work => Faire une classe File
  Ajouter une classe File dans le Logger
  Enregistrer toutes les infos dans le fichier de log avec la graviter du log (WARN, ERROR etc...)
  Display ou non a l'ecran les informations

 */

namespace zia
{

  namespace utils
  {
    class Logger : public Singleton< Logger >, NonCopyable
    {
    public:

      enum LogLevel
	{
	  NORMAL = 0,
	  DEBUG,
	  INFO,
	  WARNING,
	  ERROR,
	  CRITIC
	};

      static Logger& logg;

      void	logname(const std::string&);
      void	severity(LogLevel);
      void	display(bool);

      void	log(LogLevel, const std::string&);
      void	log(const std::string&); // this method consider wich msg is NORMAL

      Logger&	operator<<(const std::string&);

    public:
      Logger();
      ~Logger();

    private:
      bool		_display;
      LogLevel		_sev;
      std::string	_filename;
      std::ofstream	_file;  
    };

  }

  template class utils::Singleton< utils::Logger >;

  extern utils::Logger& log;
  
}


#define LOG(sev, msg) \
  zia::utils::Logger::Singleton< zia::utils::Logger >::instance()->log(sev, msg); \

#define LOG_DEBUG(msg) LOG(zia::utils::DEBUG, msg)
#define LOG_INFO(msg) LOG(zia::utils::INFO, msg)
#define LOG_WARNING(msg) LOG(zia::utils::WARNING, msg)
#define LOG_ERROR(msg) LOG(zia::utils::ERROR, msg)
#define LOG_CRITIC(msg) LOG(zia::utils::CRITIC, msg)

#endif		/* !LOGGER_HH_*/
