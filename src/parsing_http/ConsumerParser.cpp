#include <locale>
#include "parsing_http/ConsumerParser.hpp"

bool ConsumerParser::readBlock()
{
  try
    {
      std::string s(_prod.nextString());
      _buff += s;
      if (_cache.size())
      	_cache.top() += s;
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

bool ConsumerParser::readRange(char a, char b)
{
  readBlockIfEmpty();
  if(_buff[0] >= a && _buff[0] <= b)
    {
      appendText(_buff[0]);
      return true;
    }
  return false;
}

size_t findIgnoreCase(const std::string& s1, const std::string& s2)
{
  size_t ret, retmax;
  size_t i, j;

  retmax = s1.size() - s2.size();
  for (ret = 0; ret <= retmax; ++ret)
    {
      for (i = ret, j = 0;
	   i < s1.size() && j < s2.size() && toupper(s1[i]) == toupper(s2[j]);
	   ++i, ++j)
	;
      if (j == s2.size())
	return ret;
    }
  return std::string::npos;
}

bool ConsumerParser::readIgnoreCase(const std::string& s, bool keep)
{
  if (_ignoreCase)
    return read(s);
  ignoreCase(true, keep);
  bool ret = read(s);
  ignoreCase(false);
  return ret;
}

bool ConsumerParser::readEOF()
{
  return !readBlockIfEmpty();
}

bool ConsumerParser::readUntilEOF()
{
  std::string save;

  while (!readEOF())
    {
      save += _buff[0];
      _buff = _buff.substr(1);
    }
  appendText(save, false);
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
  if (!(readRange('a', 'z') || readRange('A', 'Z') || read('_')))
    return false;
  while (readRange('0', '9') || readRange('a', 'z') || readRange('A', 'Z') || read('_'))
    ;
  return true;
}


bool ConsumerParser::ignoreCase(bool ignore, bool keepSame)
{
  _ignoreCase = ignore;
  if (ignore)
    _ignoreCaseKeepSame = keepSame;
  return true;
}


bool ConsumerParser::saveContext()
{
  _cache.push(_buff);
  return true;
}

bool ConsumerParser::restoreContext()
{
  if (!_cache.size())
    return false;
  _buff = _cache.top();
  _cache.pop();
  return true;
}

bool ConsumerParser::validContext()
{
  if (!_cache.size())
    return false;
  std::string save = _cache.top();
  _cache.pop();
  if (_cache.size())
    _cache.top() += save;
  return true;
}
