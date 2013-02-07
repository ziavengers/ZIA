//
// ParserHttp.hpp for  in /home/rozo_a/Projects/tek3/piscine_parsing/d00
// 
// Made by Antoine Rozo
// Login   <rozo_a@epitech.net>
// 
// Started on  Tue Sep 11 14:28:38 2012 Antoine Rozo
// Last update Thu Feb  7 10:04:18 2013 Antoine Rozo
//

#ifndef PARSERHTTP_HH_
#define PARSERHTTP_HH_

#include "ConsumerParser.hpp"

class ParserHttp : public ConsumerParser
{
public:
  ParserHttp(IProducterStream&);
  bool readHttp(std::map<std::string, std::string>&);
  bool readCRLF();
  bool readLWS();
};

#endif
