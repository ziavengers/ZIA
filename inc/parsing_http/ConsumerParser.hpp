#ifndef CONSUMERPARSER_HPP_
#define CONSUMERPARSER_HPP_

#include <map>
#include <stack>
#include <vector>
#include "IProducterStream.hh"

// Raccourcir les noms de méthodes

// Modifier la gestion de la casse:
// Ajouter une méthode pour ignorer de façon globale la casse

// Ajouter de nouvelles fonctions prenant un tableau en param
// Et étant valables pour l'un ou l'autre des éléments du tableau

// Ajouter méthodes endAllCaptures(), restoreAllContexts(), et validAllContexts() ?

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
  inline bool peek(char c)
  {
    readBlockIfEmpty();
    return (_buff[0] == c);
  }
  inline bool peek(const std::string& s)
  {
    readBlockIfEmpty(s.size());
    return (_buff.find(s) == 0);
  }
  template < typename T >
  inline bool read(T text)
  {
    if (peek(text))
      {
	appendText(text);
	return true;
      }
    return false;
  }
  
  template < typename T >
  bool readUntil(const std::vector< T >& vec)
  {
    typename std::vector< T >::const_iterator it;
    bool ret;
    std::string save;

    ret = false;
    while (readBlockIfEmpty() && !ret)
      {
	for (it = vec.begin(); it != vec.end(); ++it)
	  if ((ret = peek(*it)))
	    break ;
	if (ret)
	  {
	    save += *it;
	    _buff = _buff.substr(textLen(*it));
	  }
	else
	  {
	    save += _buff[0];
	    _buff = _buff.substr(1);
	  }
      }
    if (ret)
      appendText(save, false);
    else
      _buff = save + _buff;
    return ret;
  }
  template < typename T >
  bool readUntil(T text)
  {
    typename std::vector< T > vec(1);
    vec[0] = text;
    return readUntil(vec);
  }

  bool readRange(char, char);
  bool readIgnoreCase(const std::string&, bool keep = true);
  bool readEOF();
  bool readUntil(char);
  bool readUntil(const std::string&);
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
