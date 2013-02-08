//
// ConsumerParser.cpp for  in /home/rozo_a/Projects/tek3/piscine_parsing/d00
// 
// Made by Antoine Rozo
// Login   <rozo_a@epitech.net>
// 
// Started on  Tue Sep 11 11:16:04 2012 Antoine Rozo
// Last update Fri Feb  8 10:56:35 2013 Antoine Rozo
//

#include "parsing_http/ConsumerParser.hpp"

ConsumerParser::ConsumerParser(IProducterStream& prod) : _prod(prod), _buff(), _tags()
{}

// ConsumerParser& ConsumerParser::operator=(const ConsumerParser& other)
// {
//   _buff = other._buff;
//   return *this;
// }

bool ConsumerParser::readBlock()
{
  try
    {
      _buff += _prod.nextString();
      return true;
    }
  catch (...)
    {
      return false;
    }
}

bool ConsumerParser::readBlockIfEmpty(size_t len)
{
  bool ret = true;
  while (_buff.size() < len && (ret = readBlock()))
    ;
  return ret;
}

bool ConsumerParser::readText(const std::string& s)
{
  readBlockIfEmpty(s.size());
  if (_buff.find_first_of(s) == 0)
    {
      std::map<std::string, std::string>::iterator it;
      for (it = _tags.begin(); it != _tags.end(); ++it)
	it->second += s;
      _buff = _buff.substr(s.size());
      return true;
    }
  return false;
}

bool ConsumerParser::readEOF()
{
  return !readBlockIfEmpty();
}

bool ConsumerParser::readUntil(char c)
{
  bool ret;
  std::string save;

  while (readBlockIfEmpty() && !(ret = readChar(c)))
    {
      save += _buff[0];
      _buff = _buff.substr(1);
    }
  if (ret)
    {
      std::map<std::string, std::string>::iterator it;
      for (it = _tags.begin(); it != _tags.end(); ++it)
	it->second.insert(it->second.size() - 1, save);
    }
  else
    _buff = save + _buff;
  return ret;
}

bool ConsumerParser::readUntilEOF()
{
  std::string save;

  while (!readEOF())
    {
      save += _buff[0];
      _buff = _buff.substr(1);
    }
  std::map<std::string, std::string>::iterator it;
  for (it = _tags.begin(); it != _tags.end(); ++it)
    it->second += save;
  return true;
}

bool ConsumerParser::readInteger()
{
  if (!readRange('0', '9'))
    return false;
  while (readRange('0', '9'))
    ;
  return true;
}

bool ConsumerParser::readIdentifier()
{
  if (!(readRange('a', 'z') || readRange('A', 'Z') || readChar('_')))
    return false;
  while (readRange('0', '9') || readRange('a', 'z') || readRange('A', 'Z') || readChar('_'))
    ;
  return true;
}

void ConsumerParser::save()
{}

void ConsumerParser::restore()
{}
