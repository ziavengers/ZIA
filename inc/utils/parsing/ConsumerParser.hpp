#ifndef CONSUMERPARSER_HPP_
#define CONSUMERPARSER_HPP_

#include <map>
#include <stack>
#include <vector>
#include "IProducterStream.hh"

namespace zia
{
  namespace utils
  {
    namespace parsing
    {

      // Ajouter méthodes endAllCaptures(), restoreAllContexts(), et validAllContexts() ?

      size_t findIgnoreCase(const std::string&, const std::string&);

      class ConsumerParser
      {
      public:
	ConsumerParser(IProducterStream& prod) : _prod(prod), _buff(), _tags(), _cache(), _ignoreCase(false), _ignoreCaseKeepSame(true)
	{}

      private:
	bool readBlock();
	bool readBlockIfEmpty(size_t = 1);
	size_t textLen(const std::string& text)
	{
	  return text.size();
	}
	size_t textLen(char)
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

      protected:
	inline bool ignore(bool)
	{
	  return true;
	}

	inline bool peek(char c)
	{
	  readBlockIfEmpty();
	  return (_ignoreCase ? toupper(_buff[0]) == toupper(c) : _buff[0] == c);
	}
	inline bool peek(const std::string& s)
	{
	  readBlockIfEmpty(s.size());
	  return (_ignoreCase ? findIgnoreCase(_buff, s) == 0 : _buff.find(s) == 0);
	}
	template < typename T >
	inline bool read(T text)
	{
	  if (peek(text))
	    {
	      if (_ignoreCase && _ignoreCaseKeepSame)
		appendText(_buff.substr(0, textLen(text)));
	      else
		appendText(text);
	      return true;
	    }
	  return false;
	}
  
	template < typename T >
	bool readUntil(const std::vector< T >& vec, bool contains = true)
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
		  if (contains)
		    {
		      save += *it;
		      _buff = _buff.substr(textLen(*it));
		    }
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
	bool readUntil(T text, bool contains = true)
	{
	  typename std::vector< T > vec(1);
	  vec[0] = text;
	  return readUntil(vec, contains);
	}

	bool readRange(char, char);
	bool readIgnoreCase(const std::string&, bool keep = true);
	bool readEOF();
	bool readUntil(char);
	bool readUntil(const std::string&);
	bool readUntilEOF();
	bool readInteger();
	bool readIdentifier();

	bool ignoreCase(bool = true, bool = true);

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
	bool _ignoreCase;
	bool _ignoreCaseKeepSame;
      };

    }
  }
}

#endif
