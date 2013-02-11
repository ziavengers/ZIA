#ifndef CONSUMERPARSER_HPP_
#define CONSUMERPARSER_HPP_

#include <map>
#include <stack>
#include "IProducterStream.hh"

class ConsumerParser
{
public:
  ConsumerParser(IProducterStream& prod) : _prod(prod), _buff(), _tags(), _cache()
  {}

private:
  bool readBlock();
  bool readBlockIfEmpty(size_t = 1);
  size_t textLen(const std::string& text)
  {
    return text.size();
  }
  size_t textLen(char c)
  {
    return 1;
  }
  template < typename T >
  void appendText(T text, bool truncBuff = true)
  {
    std::map< std::string, std::string >::iterator it;
    for (it = _tags.begin(); it != _tags.end(); ++it)
      it->second += text;
    if (truncBuff)
      _buff = _buff.substr(textLen(text));
  }

public:
  inline bool peekChar(char c)
  {
    readBlockIfEmpty();
    return (_buff[0] == c);
  }
  inline bool readChar(char c)
  {
    if (peekChar(c))
      {
	appendText(c);
	return true;
      }
    return false;
  }
  inline bool readRange(char a, char b)
  {
    readBlockIfEmpty();
    if(_buff[0] >= a && _buff[0] <= b)
      {
	appendText(_buff[0]);
	return true;
      }
    return false;
  }

  bool readText(const std::string&);
  bool readTextIgnoreCase(const std::string&, bool keep = true);
  bool readEOF();
  bool readUntil(char);
  bool readUntilEOF();
  bool readInteger();
  bool readIdentifier();

  bool saveContext();
  bool restoreContext();
  bool validContext();

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

private:
  IProducterStream& _prod;
  std::string _buff;
  std::map< std::string, std::string > _tags;
  std::stack< std::string > _cache;
};

#endif
