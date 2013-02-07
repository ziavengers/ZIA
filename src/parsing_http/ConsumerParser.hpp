//
// ConsumerParser.hpp for  in /home/rozo_a/Projects/tek3/piscine_parsing/d00
// 
// Made by Antoine Rozo
// Login   <rozo_a@epitech.net>
// 
// Started on  Tue Sep 11 11:05:02 2012 Antoine Rozo
// Last update Thu Feb  7 12:28:54 2013 Antoine Rozo
//

#ifndef CONSUMERPARSER_HPP_
#define CONSUMERPARSER_HPP_

#include <map>
#include "IProducterStream.hh"

class ConsumerParser
{
public:
  ConsumerParser(IProducterStream&);
  // ConsumerParser& operator=(const ConsumerParser&);
  inline bool peekChar(char c)
  {
    readBlockIfEmpty();
    return (_buff[0] == c);
  }
  inline bool readChar(char c)
  {
    if (peekChar(c))
      {
	std::map<std::string, std::string>::iterator it;
	for (it = _tags.begin(); it != _tags.end(); ++it)
	  it->second += c;
	_buff = _buff.substr(1);
	return true;
      }
    return false;
  }
  inline bool readRange(char a, char b)
  {
    readBlockIfEmpty();
    if(_buff[0] >= a && _buff[0] <= b)
      {
	std::map<std::string, std::string>::iterator it;
	for (it = _tags.begin(); it != _tags.end(); ++it)
	  it->second += _buff[0];
	_buff = _buff.substr(1);
	return true;
      }
    return false;
  }

  bool readText(const std::string&);
  bool readEOF();
  bool readUntil(char);
  bool readUntilEOF();
  bool readInteger();
  bool readIdentifier();

  inline bool beginCapture(std::string tag)
  {
    if (!readBlockIfEmpty())
      return false;
    _tags[tag] = "";
    return true;
  }
  inline bool endCapture(std::string tag, std::string& out)
  {
    std::map<std::string, std::string>::iterator it;
    
    if ((it = _tags.find(tag)) == _tags.end())
      return false;
    out = it->second;
    _tags.erase(it);
    return (out.size() > 0);
  }

  void save();
  void restore();

private:
  IProducterStream& _prod;
  bool readBlock();
  bool readBlockIfEmpty(size_t = 1);
  std::string _buff;
  std::map<std::string, std::string> _tags;
};

#endif
